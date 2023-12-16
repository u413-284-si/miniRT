# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: u413q <u413q@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 13:03:05 by gwolf             #+#    #+#              #
#    Updated: 2023/12/16 16:09:54 by u413q            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************
# *     Text effects           *
# ******************************

RESET := \033[0m
BOLD := \033[1m
BLACK := \033[30m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m

# ******************************
# *     Directories            *
# ******************************

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
LIB_DIR_FT := $(LIB_DIR)/libft
INC_DIR := inc
DEP_DIR := $(OBJ_DIR)/dep
#TEST_DIR := tests

# ******************************
# *     Libraries              *
# ******************************

LDFLAGS := -L $(LIB_DIR_FT)
LDLIBS := -lft -lm

# ******************************
# *     Vars for compiling     *
# ******************************

CC := cc
CPPFLAGS := -I $(INC_DIR) -I lib/libft/include
CFLAGS = -Wall -Werror -Wextra -g
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE = $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS) -c
POSTCOMPILE = @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

# ******************************
# *     Targets                *
# ******************************

NAME := miniRT
BONUSNAME := miniRT_supreme
LIBFT := $(LIB_DIR_FT)/libft.a
#TEST := test

# ******************************
# *     Source files           *
# ******************************

SRC :=	camera.c \
		colour.c \
		hit_cylinder.c \
		hit_plane.c \
		hit_sphere.c \
		hit.c \
		ray.c \
		scene_init.c \
		scene_light.c \
		scene_shadow.c \
		utils_cylinder.c \
		utils_init.c \
		utils_math.c \
		vec3_arithmetics.c \
		vec3_linalgebra.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

SRC_B := camera_bonus.c \
		colour_bonus.c \
		hit_cylinder_bonus.c \
		hit_plane_bonus.c \
		hit_sphere_bonus.c \
		hit_bonus.c \
		ray_bonus.c \
		scene_init_bonus.c \
		scene_light_bonus.c \
		scene_shadow_bonus.c \
		utils_camera_bonus.c \
		utils_cylinder_bonus.c \
		utils_init_bonus.c \
		utils_math_bonus.c \
		utils_random_bonus.c \
		vec3_arithmetics_bonus.c \
		vec3_linalgebra_bonus.c

SRCS_B := $(addprefix $(SRC_DIR)/, $(SRC_B))

# ******************************
# *     Object files           *
# ******************************

OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

OBJ_B := $(SRC_B:.c=.o)
OBJS_B := $(addprefix $(OBJ_DIR)/, $(OBJ_B))

OBJ_MAIN = $(OBJ_DIR)/main.o
OBJ_B_MAIN = $(OBJ_DIR)/main_bonus.o

# ******************************
# *     Dependency files       *
# ******************************

DEPFILES = $(SRC:%.c=$(DEP_DIR)/%.d)

DEPFILES_B = $(SRC_B:%.c=$(DEP_DIR)/%.d)

# add dependency for main, since not in SRC
DEPFILES += $(DEP_DIR)/main.d

DEPFILES_B += $(DEP_DIR)/main_bonus.d

# ******************************
# *     Test files             *
# ******************************

#TEST_SRC := 
#TEST_SRCS := $(addprefix $(TEST_DIR)/, $(TEST_SRC))
#TEST_OBJ := $(TEST_SRC:.c=.o)
#TEST_OBJS := $(addprefix $(TEST_DIR)/, $(TEST_OBJ))
#TEST_OBJ_MAIN = $(TEST_DIR)/test_main.o

.PHONY: all
all: $(NAME)

.PHONY: BONUS
bonus: $(BONUSNAME)

# ******************************
# *     NAME linkage           *
# ******************************

# Linking the NAME target
$(NAME): $(LIBFT) $(OBJS) $(OBJ_MAIN)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE) $@ $(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS) $(OBJ_MAIN) $(LDLIBS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE) $@ $(RESET)]\n"
	@printf "$(BOLD)$(GREEN) $@ created!$(RESET)\n\n"

# Linking the BONUSNAME target
$(BONUSNAME): $(LIBFT) $(OBJS_B) $(OBJ_B_MAIN)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE) $@ $(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS_B) $(OBJ_B_MAIN) $(LDLIBS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE) $@ $(RESET)]\n"
	@printf "$(BOLD)$(GREEN) $@ created! 🔥$(RESET)\n\n"

# This target adds fsanitize leak checker to the flags. It needs to clean and recompile.
.PHONY: leak
leak: CFLAGS += -fsanitize=leak
leak: LDFLAGS += -fsanitize=leak
leak: clean $(NAME)
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=leak$(RESET)\n\n"

# This target adds fsanitize address checker to the flags. It needs to clean and recompile.
.PHONY: address
address: CFLAGS += -fsanitize=address
address: LDFLAGS += -fsanitize=address
address: clean $(NAME)
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=address$(RESET)\n\n"

# Perform memory check on NAME. Needs manual clean if target leak or address was called before
.PHONY: valgr
valgr: $(NAME)
	@valgrind 	--leak-check=full\
				--show-leak-kinds=all\
				--track-fds=yes\
				./$(NAME)
#			--log-file=valgrind-out.txt\
#			-s --suppressions=./minishell.supp\

#	@less ./valgrind-out.txt

# ******************************
# *     TEST linkage           *
# ******************************

# Create the binary TEST, which has its own test_main.
#$(TEST): CFLAGS = -g -gdwarf-4
#$(TEST): $(LIBFT) $(OBJS) $(TEST_OBJS) $(TEST_OBJ_MAIN)
#	@printf "\n$(YELLOW)$(BOLD)link test binary$(RESET) [$(BLUE)minishell$(RESET)]\n"
#	$(CC) $(LDFLAGS) $(OBJS) $(TEST_OBJS) $(TEST_OBJ_MAIN) $(LDLIBS) -o $@
#	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE)minishell$(RESET)]\n"
#	@printf "$(BOLD)$(GREEN)$(TEST) created!$(RESET)\n\n"

# This target adds fsanitize leak checker to the flags. It needs to clean and recompile.
#.PHONY: tleak
#tleak: CFLAGS += -fsanitize=leak
#tleak: LDFLAGS += -fsanitize=leak
#tleak: clean tclean $(TEST)
#	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=leak$(RESET)\n\n"

# This target adds fsanitize address checker to the flags. It needs to clean and recompile.
#.PHONY: taddress
#taddress: CFLAGS += -fsanitize=address
#taddress: LDFLAGS += -fsanitize=address
#taddress: clean tclean $(TEST)
#	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=address$(RESET)\n\n"

# Perform memory check on TEST. Needs manual clean if tleak or taddress was called before
#.PHONY: tvalgr
#tvalgr: $(TEST)
#	@valgrind --leak-check=full\
			--show-leak-kinds=all\
			--trace-children=no\
			--track-fds=no\
			--log-file=valgrind-out.txt\
			--suppressions=./minishell.supp
#			./$(TEST)
#	@less ./valgrind-out.txt

# ******************************
# *     Object compiling and   *
# *     dependecy creation     *
# ******************************

# Create object and dependency files
# $(DEP_DIR)/%.d =	Declare the generated dependency file as a prerequisite of the target,
# 					so that if it’s missing the target will be rebuilt.
# | $(DEPDIR) = 	Declare the dependency directory as an order-only prerequisite of the target,
# 					so that it will be created when needed.
# $(POSTCOMPILE) =	Move temp dependency file and touch object to ensure right timestamps.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d message | $(DEP_DIR)
	$(COMPILE) $< -o $@
	$(POSTCOMPILE)

# Print message only if there are objects to compile
.INTERMEDIATE: message
message:
	@printf "\n$(YELLOW)$(BOLD)compile objects$(RESET) [$(BLUE)miniRT$(RESET)]\n"

# Create objects from test source files
$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Create directory obj/dep if it doesn't exist
$(DEP_DIR):
	@printf "\n$(YELLOW)$(BOLD)create subdir$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	mkdir -p $@

# Mention each dependency file as a target, so that make won’t fail if the file doesn’t exist.
$(DEPFILES):

$(DEPFILES_B):

# ******************************
# *     External Libraries     *
# ******************************

# Use Makefile of libft to compile the library.
$(LIBFT):
	@printf "$(YELLOW)$(BOLD)compilation$(RESET) [$(BLUE)libft$(RESET)]\n"
	$(MAKE) -s -C $(LIB_DIR)/libft

# ******************************
# *     Cleanup                *
# ******************************

.PHONY: clean
clean:
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)$(NAME)/$(BONUSNAME)$(RESET)]\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

# Clean test objects and tester
#.PHONY: tclean
#tclean:
#	@rm -rf $(TEST_DIR)/*.o
#	@printf "$(RED)removed .o files in subdir $(TEST_DIR)$(RESET)\n"
#	@rm -rf $(TEST)
#	@printf "$(RED)clean bin $(TEST)$(RESET)\n"

.PHONY: fclean
fclean: clean
	@printf "$(RED)clean bin $(NAME)/$(BONUSNAME)$(RESET)\n"
	@rm -rf $(NAME)
	@rm -rf $(BONUSNAME)
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)libft$(RESET)]\n"
	@$(MAKE) --no-print-directory -C $(LIB_DIR_FT) fclean

# ******************************
# *     Recompilation          *
# ******************************

.PHONY: re
re: fclean all

# ******************************
# *     Various                *
# ******************************

# Include the dependency files that exist. Use wildcard to avoid failing on non-existent files.
# Needs to be last target
include $(wildcard $(DEPFILES))

include $(wildcard $(DEPFILES_B))
