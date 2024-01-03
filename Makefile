# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 13:03:05 by gwolf             #+#    #+#              #
#    Updated: 2024/01/01 18:00:27 by sqiu             ###   ########.fr        #
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

SRC := 	camera.c \
		check_entity_ACL.c \
		check_entity_sp_pl_cy.c \
		check_line.c \
		check.c \
		cleanup.c \
		colour.c \
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
		parse_entity_ACL.c \
		parse_entity_sp_pl_cy.c \
		parse_line.c \
		parse.c \
		ray.c \
		render_draw.c \
		render_init_mlx.c \
		render_keyhook.c \
		render_loop_mlx.c \
		render_output_ppm.c \
		scene_init.c \
		scene_light.c \
		scene_shadow.c \
		utils_cylinder.c \
		utils_interval.c \
		utils_math.c \
		vec3_arithmetics.c \
		vec3_linalgebra.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

SRC_B := camera_bonus.c \
		check_entity_ACL_bonus.c \
		check_entity_sp_pl_cy_bonus.c \
		check_line_bonus.c \
		check_bonus.c \
		cleanup_bonus.c \
		colour_bonus.c \
		error_mlx_bonus.c \
		error_msg_check_bonus.c \
		error_msg_generic_bonus.c \
		error_syscall_bonus.c \
		ft_strtod.c \
		geometric_transform.c \
		hit_cone_bonus.c \
		hit_cylinder_bonus.c \
		hit_plane_bonus.c \
		hit_sphere_bonus.c \
		hit_bonus.c \
		import_file_buffer_bonus.c \
		import_file_bonus.c \
		main_bonus.c \
		mat4_rotation.c \
		mat4_vec3_rotate.c \
		mat4.c \
		parse_entity_ACL_bonus.c \
		parse_entity_sp_pl_cy_bonus.c \
		parse_line_bonus.c \
		parse_bonus.c \
		ray_bonus.c \
		render_draw_bonus.c \
		render_init_mlx_bonus.c \
		render_keyhook_bonus.c \
		render_loop_mlx_bonus.c \
		render_output_ppm_bonus.c \
		scene_init_bonus.c \
		scene_light_bonus.c \
		scene_reflection_bonus.c \
		scene_shadow_bonus.c \
		utils_camera_bonus.c \
		utils_cone_bonus.c \
		utils_cylinder_bonus.c \
		utils_interval_bonus.c \
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

# ******************************
# *     Dependency files       *
# ******************************

DEPFILES = $(SRC:%.c=$(DEP_DIR)/%.d)

DEPFILES_B = $(SRC_B:%.c=$(DEP_DIR)/%.d)

# ******************************
# *     Default target         *
# ******************************

.PHONY: all
all: $(NAME)

.PHONY: BONUS
bonus: CFLAGS = -Ofast -march=native
bonus: LDFLAGS += -flto
bonus: $(BONUSNAME)

# ******************************
# *     NAME linkage           *
# ******************************

# Linking the NAME target
$(NAME): $(LIBFT) $(OBJS)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE) $@ $(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE) $@ $(RESET)]\n"
	@printf "$(BOLD)$(GREEN) $@ created!$(RESET)\n\n"

# Linking the BONUSNAME target
$(BONUSNAME): $(LIBFT) $(OBJS_B)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE) $@ $(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS_B) $(LDLIBS) -o $@
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

$(DEPFILES_B):

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
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)$(NAME)/$(BONUSNAME)$(RESET)]\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

.PHONY: fclean
fclean: clean
	@printf "$(RED)clean bin $(NAME)/$(BONUSNAME)$(RESET)\n"
	@rm -rf $(NAME)
	@rm -rf $(BONUSNAME)
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

include $(wildcard $(DEPFILES_B))
