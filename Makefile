# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 13:03:05 by gwolf             #+#    #+#              #
#    Updated: 2023/12/17 10:50:45 by gwolf            ###   ########.fr        #
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
LDLIBS := -lft -lm -lmlx -lXext -lX11

# ******************************
# *     Vars for compiling     *
# ******************************

CC := cc
CPPFLAGS := -I $(INC_DIR) -I lib/libft/include
CFLAGS = -Wall -Werror -Wextra -gdwarf-4
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE = $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS) -c
POSTCOMPILE = @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

# ******************************
# *     Targets                *
# ******************************

NAME := miniRT
LIBFT := $(LIB_DIR_FT)/libft.a
#TEST := test

# ******************************
# *     Source files           *
# ******************************

SRC :=	camera_init_update.c \
		camera_move.c \
		camera_view.c \
		check_entity_ACL.c \
		check_entity_sp_pl_cy.c \
		check_line.c \
		check.c \
		cleanup.c \
		colour.c \
		engine_keyhook_camera.c \
		engine_keyhook_hittable.c \
		engine_keyhook.c \
		engine_loop.c \
		engine_mouse.c \
		error_mlx.c \
		error_msg_check.c \
		error_msg_generic.c \
		error_syscall.c \
		ft_strtod.c \
		hit_cylinder.c \
		hit_plane.c \
		hit_sphere.c \
		hit.c \
		import_file_buffer.c \
		import_file.c \
		main.c \
		mat4_inverse.c \
		mat4_rotation.c \
		mat4_transform.c \
		mat4.c \
		output_ppm.c \
		parse_entity_ACL.c \
		parse_entity_sp_pl_cy.c \
		parse_line.c \
		parse.c \
		print_hittable.c \
		ray.c \
		render_draw.c \
		render_init.c \
		render_put_num_utils.c \
		render_put_num.c \
		scene_init.c \
		scene_light.c \
		scene_shadow.c \
		utils_cylinder.c \
		utils.c \
		vec3_arithmetics.c \
		vec3_linalgebra.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

# ******************************
# *     Object files           *
# ******************************

OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

# ******************************
# *     Dependency files       *
# ******************************

DEPFILES = $(SRC:%.c=$(DEP_DIR)/%.d)

# ******************************
# *     Default target         *
# ******************************

.PHONY: all
all: check_flags $(NAME)

# ******************************
# *     NAME linkage           *
# ******************************

# Linking the NAME target
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(CFLAGS)" > $(OBJ_DIR)/.last_build_flags
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@printf "$(BOLD)$(GREEN)$(NAME) created!$(RESET)\n\n"

# This target adds fsanitize leak checker to the flags. It needs to clean and recompile.
.PHONY: leak
leak: CFLAGS += -fsanitize=leak
leak: LDFLAGS += -fsanitize=leak
leak: check_flags $(NAME)
	@echo "$(CFLAGS)" > $(OBJ_DIR)/.last_build_flags
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=leak$(RESET)\n\n"

# This target adds fsanitize address checker to the flags. It needs to clean and recompile.
.PHONY: address
address: CFLAGS += -fsanitize=address
address: LDFLAGS += -fsanitize=address
address: check_flags $(NAME)
	@echo "$(CFLAGS)" > $(OBJ_DIR)/.last_build_flags
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

# This target has optimized flags for speed.
.PHONY: speed
speed: CFLAGS = -Ofast -march=native -fomit-frame-pointer
speed: LDFLAGS += -flto
speed: check_flags $(NAME)
	@echo "$(CFLAGS)" > $(OBJ_DIR)/.last_build_flags
	@printf "Compiled with $(YELLOW)$(BOLD)speed$(RESET)\n\n"

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

# Create directory obj/dep if it doesn't exist
$(DEP_DIR):
	@printf "\n$(YELLOW)$(BOLD)create subdir$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	mkdir -p $@

# Mention each dependency file as a target, so that make won’t fail if the file doesn’t exist.
$(DEPFILES):

.PHONY: check_flags
check_flags:
	@if [ -f $(OBJ_DIR)/.last_build_flags ]; then \
		if [ "$$(cat $(OBJ_DIR)/.last_build_flags)" != "$(CFLAGS)" ]; then \
			printf "\n$(YELLOW)$(BOLD)check_flags$(RESET) [$(BLUE)miniRT$(RESET)]\n"; \
			printf "CFLAGS changed, cleaning $(OBJ_DIR)\n"; \
			rm -f $(OBJ_DIR)/*.o; \
		fi \
	fi

# ******************************
# *     External Libraries     *
# ******************************

# Use Makefile of libft to compile the library.
$(LIBFT):
	@printf "$(YELLOW)$(BOLD)compilation$(RESET) [$(BLUE)libft$(RESET)]\n"
	@$(MAKE) --no-print-directory -C $(LIB_DIR)/libft

# ******************************
# *     Cleanup                *
# ******************************

.PHONY: clean
clean:
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)clean bin $(NAME)$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)libft$(RESET)]\n"
	@$(MAKE) --no-print-directory -C $(LIB_DIR_FT) fclean
	@echo

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
