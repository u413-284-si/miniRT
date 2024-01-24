# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 13:03:05 by gwolf             #+#    #+#              #
#    Updated: 2024/01/24 11:03:52 by gwolf            ###   ########.fr        #
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
# Subdirectories for base, and bonus object files
OBJ_DIR_BASE := $(BASE_OBJ_DIR)/base
OBJ_DIR_BONUS := $(BASE_OBJ_DIR)/bonus
# Adjust directory based on MODE
ifeq ($(MODE), leak)
	OBJ_DIR_BASE := $(OBJ_DIR_BASE)/leak
	OBJ_DIR_BONUS := $(OBJ_DIR_BONUS)/leak
else ifeq ($(MODE), address)
	OBJ_DIR_BASE := $(OBJ_DIR_BASE)/address
	OBJ_DIR_BONUS := $(OBJ_DIR_BONUS)/address
else ifeq ($(MODE), thread)
	OBJ_DIR_BASE := $(OBJ_DIR_BASE)/thread
	OBJ_DIR_BONUS := $(OBJ_DIR_BONUS)/thread
else ifeq ($(MODE), speed)
	OBJ_DIR_BASE := $(OBJ_DIR_BASE)/speed
	OBJ_DIR_BONUS := $(OBJ_DIR_BONUS)/speed
else
	OBJ_DIR_BASE := $(OBJ_DIR_BASE)/default
	OBJ_DIR_BONUS := $(OBJ_DIR_BONUS)/default
endif

# Subdirectory for library files
LIB_DIR := lib
LIB_DIR_FT := $(LIB_DIR)/libft

# Subdirectory for header files
INC_DIR := inc

# Subdirectories for dependency files
DEP_DIR_BASE := $(OBJ_DIR_BASE)/dep
DEP_DIR_BONUS := $(OBJ_DIR_BONUS)/dep

# Subdirectory for log files
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
# *     Modifying CFLAGS       *
# *     and LDFLAGS            *
# ******************************

ifeq ($(MODE), leak)
	CFLAGS += -fsanitize=leak
	LDFLAGS += -fsanitize=leak
else ifeq ($(MODE), address)
	CFLAGS += -fsanitize=address
	LDFLAGS += -fsanitize=address
else ifeq ($(MODE), thread)
	CFLAGS += -fsanitize=thread
	LDFLAGS += -fsanitize=thread
else ifeq ($(MODE), speed)
	CFLAGS = -Ofast -march=native
	LDFLAGS += -flto
endif

# ******************************
# *     Targets                *
# ******************************

# Base target
BASE := miniRT
# Bonus target
BONUS := miniRT_supreme
# Set default target name
ifneq (,$(findstring bonus,$(MAKECMDGOALS)))
	DEFAULT = $(BONUS)
else
	DEFAULT = $(BASE)
endif

# Set target name to default
NAME = $(DEFAULT)

# Append for fsanitize leak checker
LEAK := _leak
# Append for fsanitize address checker
ADDRESS := _address
# Append for fsanitize thread checker
THREAD := _thread
# Append for speed optimization
SPEED := _speed

# Modify name depending on MODE variable
ifeq ($(MODE), leak)
	NAME = $(DEFAULT)$(LEAK)
else ifeq ($(MODE), address)
	NAME = $(DEFAULT)$(ADDRESS)
else ifeq ($(MODE), thread)
	NAME = $(DEFAULT)$(THREAD)
else ifeq ($(MODE), speed)
	NAME = $(DEFAULT)$(SPEED)
endif

# Library target libft
LIBFT := $(LIB_DIR_FT)/libft.a

# ******************************
# *     Source files           *
# ******************************

SRC_COMMON := 	camera_movement.c \
				camera.c \
				check.c \
				check_entity_ACL.c \
				check_entity_sp_pl_cy.c \
				check_line.c \
				check_rm_space.c \
				cleanup.c \
				debug_print_entity.c \
				debug_print_struct.c \
				error_msg_check2.c \
				error_msg_generic.c \
				error_mlx.c \
				error_syscall.c \
				ft_strtod.c \
				import_file.c \
				import_file_buffer.c \
				main.c \
				menu_init.c \
				menu_put_cam_light.c \
				menu_put_cam_light_ctrl.c \
				menu_put_general_info.c \
				menu_put_hittable.c \
				menu_put_hittable_ctrl.c \
				menu_put_page.c \
				menu_put_str_num.c \
				menu_put_utils.c \
				menu_put_utils_ctrl.c \
				parse.c \
				parse_entity_ACL.c \
				parse_entity_sp_pl_cy.c \
				parse_line.c \
				ray.c \
				render_bit_field.c \
				render_blend_background.c \
				render_cleanup.c \
				render_init_mlx.c \
				render_keyhook_camera.c \
				render_keyhook_colour.c \
				render_keyhook_hittable.c \
				render_keyhook_light.c \
				render_keyhook_options.c \
				render_keyhook_select.c \
				render_keyhook_utils.c \
				render_mouse.c \
				scene_shadow.c \
				utils_interval.c \
				utils_quaternion.c \
				vec3_arithmetics.c \
				vec3_linalgebra.c \

SRC_BASE := 	colour.c \
				error_msg_check.c \
				hit.c \
				hit_cylinder.c \
				hit_plane.c \
				hit_sphere.c \
				menu_put_text.c \
				render_draw.c \
				render_init_base.c \
				render_keyhook_press.c \
				render_loop_mlx.c \
				scene_light.c \
				utils_cylinder.c \
				utils_math.c \

SRC_BONUS :=	check_bonus.c \
				check_entity_sp_pl_cy_bonus.c \
				colour_bonus.c \
				error_msg_check_bonus.c \
				hit_bonus.c \
				hit_cone_bonus.c \
				hit_cylinder_bonus.c \
				hit_plane_bonus.c \
				hit_sphere_bonus.c \
				menu_put_general_info_bonus.c \
				menu_put_hittable_bonus.c \
				menu_put_hittable_ctrl_bonus.c \
				menu_put_options_bonus.c \
				menu_put_text_bonus.c \
				menu_put_time_bonus.c \
				parse_bonus.c \
				parse_entity_sp_pl_cy_bonus.c \
				render_cleanup_bonus.c \
				render_draw_bonus.c \
				render_init_bonus.c \
				render_keyhook_hittable_bonus.c \
				render_keyhook_options_bonus.c \
				render_keyhook_press_bonus.c \
				render_loop_mlx_bonus.c \
				render_output_ppm_bonus.c \
				render_output_threaded_bonus.c \
				render_sample_bonus.c \
				render_threaded_fts_bonus.c \
				scene_light_bonus.c \
				scene_reflection_bonus.c \
				texture_bonus.c \
				time_bonus.c \
				utils_cone_bonus.c \
				utils_cylinder_bonus.c \
				utils_math_bonus.c \
				utils_random_bonus.c \
				threads_bonus.c \

# ******************************
# *     Object files           *
# ******************************

OBJ_BASE = 	$(addprefix $(OBJ_DIR_BASE)/, $(SRC_BASE:.c=.o) ) \
			$(addprefix $(OBJ_DIR_BASE)/, $(SRC_COMMON:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o)) \
			$(addprefix $(OBJ_DIR_BONUS)/, $(SRC_COMMON:.c=.o))

# Depending on whether 'bonus' is a make target, use base or bonus objects
ifneq (,$(findstring bonus,$(MAKECMDGOALS)))
	OBJS = $(OBJ_BONUS)
else
	OBJS = $(OBJ_BASE)
endif

# ******************************
# *     Dependency files       *
# ******************************

DEPFILES =	$(SRC_COMMON:%.c=$(DEP_DIR_BASE)/%.d) \
			$(SRC_BASE:%.c=$(DEP_DIR_BASE)/%.d) \
			$(SRC_COMMON:%.c=$(DEP_DIR_BONUS)/%.d) \
			$(SRC_BONUS:%.c=$(DEP_DIR_BONUS)/%.d)

# ******************************
# *     Log files              *
# ******************************

DEFAULT_SCENE = scenes/basic_spheres.rt
LOG_FILE_BASE = $(LOG_DIR)/$(shell date "+%Y-%m-%d-%H-%M-%S")
LOG_VALGRIND = $(LOG_FILE_BASE)_valgrind.log
LOG_PERF = $(LOG_FILE_BASE)_perf.data

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

# This target compiles with bonus objects.
.PHONY: bonus
bonus: CFLAGS += -D IS_BONUS
bonus: $(NAME)

# This target uses perf for profiling.
.PHONY: profile
profile: check_perf_installed $(NAME) | $(LOG_DIR)
	@printf "$(YELLOW)$(BOLD)Run for profiling with perf$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@printf "Profile scene: $(DEFAULT_SCENE)\n"
	$(eval NEW_LOG_FILE=$(LOG_PERF))
	$(SILENT)perf record -g -o $(NEW_LOG_FILE) ./$(NAME) $(DEFAULT_SCENE)
	@printf "$(YELLOW)$(BOLD)Saved log file$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	@printf "$(NEW_LOG_FILE)\n"
	@printf "$(YELLOW)$(BOLD)Run perf report$(RESET) [$(BLUE)miniRT$(RESET)]\n"
	$(SILENT)perf report -g -i $(NEW_LOG_FILE)

# Check if perf is installed. If not exit with error.
.PHONY: check_perf_installed
check_perf_installed:
	@command -v perf >/dev/null 2>&1 || { \
		echo >&2 "perf is not installed. Please install perf to continue."; exit 1; \
	}

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
TOTAL_FILES := $(words $(OBJS))
CURRENT_FILE := 0

# Create object and dependency files
# $(DEP_DIR)/%.d =	Declare the generated dependency file as a prerequisite of the target,
# 					so that if it’s missing the target will be rebuilt.
# | $(DEPDIR) = 	Declare the dependency directory as an order-only prerequisite of the target,
# 					so that it will be created when needed.
# $(eval ...) =		Increment file counter.
# $(eval ...) =		Increment file counter.
# $(POSTCOMPILE) =	Move temp dependency file and touch object to ensure right timestamps.

$(OBJ_DIR_BASE)/%.o: $(SRC_DIR)/%.c message $(DEP_DIR_BASE)/%.d | $(DEP_DIR_BASE)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@echo "($(CURRENT_FILE)/$(TOTAL_FILES)) Compiling $(BOLD)$< $(RESET)"
	$(eval DEP_DIR=$(DEP_DIR_BASE))
	$(SILENT)$(COMPILE) $< -o $@
	$(SILENT)$(POSTCOMPILE)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c message $(DEP_DIR_BONUS)/%.d | $(DEP_DIR_BONUS)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@echo "($(CURRENT_FILE)/$(TOTAL_FILES)) Compiling $(BOLD)$< $(RESET)"
	$(eval DEP_DIR=$(DEP_DIR_BONUS))
	$(SILENT)$(COMPILE) $< -o $@
	$(SILENT)$(POSTCOMPILE)

# Print message only if there are objects to compile
.INTERMEDIATE: message
message:
	@printf "$(YELLOW)$(BOLD)compile objects$(RESET) [$(BLUE)miniRT$(RESET)]\n"

# Create subdirectory if it doesn't exist
$(DEP_DIR_BASE) $(DEP_DIR_BONUS) $(LOG_DIR):
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

# ******************************
# *     Help Target            *
# ******************************

.PHONY: help
help:
	@echo "$(GREEN)$(BOLD)miniRT Makefile Help$(RESET)"
	@echo "This Makefile automates the compilation and cleaning processes for miniRT."
	@echo "It supports various targets and can be customized with different variables."
	@echo "Below are the available targets and variables you can use."
	@echo ""
	@echo "$(YELLOW)Targets:$(RESET)"
	@echo "  all         - Compiles the default version of the miniRT program."
	@echo "  bonus       - Compiles the bonus version of miniRT with extra features."
	@echo "  clean       - Removes object files and dependency files."
	@echo "  fclean      - Performs 'clean' and also removes binaries and log files."
	@echo "  re          - Performs 'fclean' and then 'all'."
	@echo "  valgr       - Runs the program with Valgrind to check for memory leaks."
	@echo "  profile     - Profiles the program using 'perf'."
	@echo ""
	@echo "$(YELLOW)Variables:$(RESET)"
	@echo "  VERBOSE=1   - Echoes all commands if set to 1."
	@echo "  MODE        - Changes compilation for specific purposes. Options: leak, address, speed."
	@echo "                leak: Enables fsanitize leak checker."
	@echo "                address: Enables fsanitize address checker."
	@echo "                speed: Compiles for speed optimization."
	@echo ""
	@echo "$(YELLOW)Examples:$(RESET)"
	@echo "  make all VERBOSE=1   - Compiles the default target with command echoing."
	@echo "  make bonus MODE=leak - Compiles the bonus version with leak sanitation."
	@echo ""
	@echo "For more detailed information, read the comments within the Makefile itself."
