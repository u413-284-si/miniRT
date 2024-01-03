# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 13:03:05 by gwolf             #+#    #+#              #
#    Updated: 2024/01/03 15:02:10 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************
# *     Verbosity              *
# ******************************

# Set VERBOSE=1 to echo all commands
ifeq ($(VERBOSE),1)
	SILENT =
else
	SILENT = @
endif

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
# Base directory for object files
BASE_OBJ_DIR := obj
# Subdirectory for default compilation
OBJ_DIR_DEFAULT := $(BASE_OBJ_DIR)/default
# Subdirectory for compilation with fsanitize leak checker
OBJ_DIR_LEAK := $(BASE_OBJ_DIR)/leak
# Subdirectory for compilation with fsanitize address checker
OBJ_DIR_ADDRESS := $(BASE_OBJ_DIR)/address
# Subdirectory for compilation with speed optimization
OBJ_DIR_SPEED := $(BASE_OBJ_DIR)/speed
# Subdirectory for compilation with profiling
OBJ_DIR_PROFILE := $(BASE_OBJ_DIR)/profile
# Set default object directory
OBJ_DIR = $(OBJ_DIR_DEFAULT)
# Set object directory depending on target
ifneq (,$(findstring leak,$(MAKECMDGOALS)))
	OBJ_DIR = $(OBJ_DIR_LEAK)
else ifneq (,$(findstring address,$(MAKECMDGOALS)))
	OBJ_DIR = $(OBJ_DIR_ADDRESS)
else ifneq (,$(findstring speed,$(MAKECMDGOALS)))
	OBJ_DIR = $(OBJ_DIR_SPEED)
else ifneq (,$(findstring profile,$(MAKECMDGOALS)))
	OBJ_DIR = $(OBJ_DIR_PROFILE)
endif
LIB_DIR := lib
LIB_DIR_FT := $(LIB_DIR)/libft
INC_DIR := inc
DEP_DIR = $(OBJ_DIR)/dep
LOG_DIR := log

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

# Default target
DEFAULT := miniRT
# Target for fsanitize leak checker
LEAK := $(DEFAULT)_leak
# Target for fsanitize address checker
ADDRESS := $(DEFAULT)_address
# Target for speed optimization
SPEED := $(DEFAULT)_speed
# Target for profiling
PROFILE := $(DEFAULT)_profile
# Set default target
NAME = $(DEFAULT)
# Set target depending on target
ifneq (,$(findstring leak,$(MAKECMDGOALS)))
	NAME = $(LEAK)
else ifneq (,$(findstring address,$(MAKECMDGOALS)))
	NAME = $(ADDRESS)
else ifneq (,$(findstring speed,$(MAKECMDGOALS)))
	NAME = $(SPEED)
else ifneq (,$(findstring profile,$(MAKECMDGOALS)))
	NAME = $(PROFILE)
endif
LIBFT := $(LIB_DIR_FT)/libft.a

# ******************************
# *     Source files           *
# ******************************

SRC :=	camera_movement.c \
		camera.c \
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
		mat4_rotation.c \
		mat4_vec3_rotate.c \
		mat4.c \
		menu_draw.c \
		menu_init.c \
		menu_put_camera_lights.c \
		menu_put_ctrl_base.c \
		menu_put_ctrl_cam_lights.c \
		menu_put_ctrl_hittable.c \
		menu_put_element.c \
		menu_put_hittable.c \
		menu_put_mode.c \
		menu_put_num.c \
		parse_entity_ACL.c \
		parse_entity_sp_pl_cy.c \
		parse_line.c \
		parse.c \
		print_entity.c \
		print_struct.c \
		ray.c \
		render_draw.c \
		render_init_mlx.c \
		render_keyhook_camera.c \
		render_keyhook_hittable.c \
		render_keyhook_light.c \
		render_keyhook_utils.c \
		render_keyhook.c \
		render_loop_mlx.c \
		render_mouse.c \
		render_output_ppm.c \
		scene_init.c \
		scene_light.c \
		scene_shadow.c \
		utils_entities.c \
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
# *     Log files              *
# ******************************

DEFAULT_SCENE = scenes/basic_spheres.rt
LOG_FILE_BASE = $(LOG_DIR)/$(shell date "+%Y-%m-%d-%H-%M-%S")
LOG_VALGRIND = $(LOG_FILE_BASE)_valgrind.log
LOG_GPROF = $(LOG_FILE_BASE)_gprof.log

# ******************************
# *     Default target         *
# ******************************

.PHONY: all
all: $(NAME)

# ******************************
# *     NAME linkage           *
# ******************************

# Linking the NAME target
$(NAME): $(LIBFT) $(OBJS)
	@printf "$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	$(SILENT)$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@
	@printf "$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@printf "$(BOLD)$(GREEN)$(NAME) created!$(RESET)\n"

# ******************************
# *     Special targets        *
# ******************************

# This target adds fsanitize leak checker to the flags.
.PHONY: leak
leak: CFLAGS += -fsanitize=leak
leak: LDFLAGS += -fsanitize=leak
leak: $(NAME)

# This target adds fsanitize address checker to the flags.
.PHONY: address
address: CFLAGS += -fsanitize=address
address: LDFLAGS += -fsanitize=address
address: $(NAME)

# This target adds flags which optimize the program for speed.
.PHONY: speed
speed: CFLAGS = -Ofast -march=native
speed: LDFLAGS += -flto
speed: $(NAME)

# This target adds flags which enable profiling.
.PHONY: profile
profile: CFLAGS += -pg
profile: LDFLAGS += -pg
profile: $(NAME) | $(LOG_DIR)
	@printf "\n$(YELLOW)$(BOLD)Run for profiling$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@printf "Profile scene: $(DEFAULT_SCENE)\n"
	$(SILENT)./$(NAME) $(DEFAULT_SCENE)
	$(SILENT)gprof $(NAME) gmon.out > $(LOG_GPROF)
	@printf "\n$(YELLOW)$(BOLD)Saved log file$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	$(SILENT)rm gmon.out
	$(SILENT)ls -dt1 $(LOG_DIR)/* | head -n 1 | xargs less

# Perform memory check on NAME.
.PHONY: valgr
valgr: $(NAME) | $(LOG_DIR)
	$(SILENT)valgrind	--leak-check=full\
						--show-leak-kinds=all\
						--track-fds=yes\
						--log-file=$(LOG_VALGRIND)\
						./$(NAME) $(DEFAULT_SCENE)
	$(SILENT)ls -dt1 $(LOG_DIR)/* | head -n 1 | xargs less

# ******************************
# *     Object compiling and   *
# *     dependecy creation     *
# ******************************

# File counter for status output
TOTAL_FILES := $(words $(SRC))
CURRENT_FILE := 0

# Create object and dependency files
# $(DEP_DIR)/%.d =	Declare the generated dependency file as a prerequisite of the target,
# 					so that if it’s missing the target will be rebuilt.
# | $(DEPDIR) = 	Declare the dependency directory as an order-only prerequisite of the target,
# 					so that it will be created when needed.
# $(eval ...) =		Increment file counter.
# $(POSTCOMPILE) =	Move temp dependency file and touch object to ensure right timestamps.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d message | $(DEP_DIR)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@echo "($(CURRENT_FILE)/$(TOTAL_FILES)) Compiling $(BOLD)$< $(RESET)"
	$(SILENT)$(COMPILE) $< -o $@
	$(SILENT)$(POSTCOMPILE)

# Print message only if there are objects to compile
.INTERMEDIATE: message
message:
	@printf "$(YELLOW)$(BOLD)compile objects$(RESET) [$(BLUE)miniRT$(RESET)]\n"

# Create obj and dep subdirectory if it doesn't exist
$(DEP_DIR):
	@printf "$(YELLOW)$(BOLD)create subdir$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@echo $@
	$(SILENT)mkdir -p $@

$(LOG_DIR):
	@printf "$(YELLOW)$(BOLD)create subdir$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@echo $@
	$(SILENT)mkdir -p $@

# Mention each dependency file as a target, so that make won’t fail if the file doesn’t exist.
$(DEPFILES):

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

# Remove all object files and dependency files
.PHONY: clean
clean:
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@rm -rf $(BASE_OBJ_DIR)
	@printf "$(RED)removed subdir $(BASE_OBJ_DIR)$(RESET)\n"

# Remove all object, dependency, binaries and log files
.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)*
	@printf "$(RED)removed binaries $(NAME)*$(RESET)\n"
	@rm -rf $(LOG_DIR)
	@printf "$(RED)removed subdir $(LOG_DIR)$(RESET)\n"
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
