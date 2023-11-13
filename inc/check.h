/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:37:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/12 16:13:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

/* ====== LIBRARIES ====== */

# include <float.h>
# include <math.h>

# include "miniRT_error.h"
# include "ft_char.h"
# include "cleanup.h"

/* ===== DEFINES ===== */

# define ENTITIES 6
# define AMBIENT_MAX 1
# define CAMERA_MAX 1
# define LIGHT_MAX 1
# define SPHERE_MAX 100
# define PLANE_MAX 100
# define CYLINDER_MAX 100

# define FLOAT_MIN -1000.0
# define FLOAT_MAX 1000.0

/* ====== TYPEDEFS ====== */

/**
 * @brief Enumeration of different entity types.
 */
typedef enum e_entity_type {
	UNKNOWN = -1,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_entity_type;

/* ====== FUNCTIONS ====== */

// check_file.c
t_err	ft_check_file(char *filename, char ***lines, int entity_count[ENTITIES]);
bool	ft_check_filename(char *filename);
t_err	ft_import_file(int fd, char ***lines);
t_err	ft_check_line(char **lines, int entity_count[ENTITIES]);
t_entity_type	ft_is_valid_line(char *line);

// ft_strtod.c
double	ft_strtod(const char *str, size_t *offset);

// check_line.c
void	ft_skip_space(char **line);
bool	ft_is_valid_float(char **line, float min, float max);
bool	ft_is_valid_float_block(char **line, float min, float max);
bool	ft_is_valid_rgb_val(char **line);
bool	ft_is_valid_rgb_block(char **line);

// check_entity1.c
t_entity_type	ft_check_ambient(char *line);
t_entity_type	ft_check_camera(char *line);
t_entity_type	ft_check_light(char *line);

// check_entity2.c
t_entity_type	ft_check_sphere(char *line);
t_entity_type	ft_check_plane(char *line);
t_entity_type	ft_check_cylinder(char *line);

#endif