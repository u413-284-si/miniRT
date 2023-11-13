/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:37:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 19:28:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

/* ====== LIBRARIES ====== */

# include <math.h>

# include "miniRT_error.h"
# include "ft_char.h"
# include "cleanup.h"
# include "ft_strtod.h"

/* ===== MACROS ===== */

# define BUF_SIZE 20

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
 * @brief Buffer structure.
 *
 * Simple implementation of a buffer.
 * @param str		Buffer string.
 * @param size		Size of malloced buffer memory in Bytes.
 * @param cur_pos	Current position inside malloced buffer
 * 					memory.
 */
typedef struct s_buf
{
	char	*str;
	size_t	size;
	size_t	cur_pos;
}	t_buf;

/**
 * @brief Enumeration of different entity types.
 * @param UNKOWN	If not recognized
 * @param SUM_ENTS	Amounts to sum of all entity types.
 */
typedef enum e_entity_type {
	UNKNOWN = -1,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	SUM_ENTS
}	t_ent_type;

/* ====== FUNCTIONS ====== */

// check_file.c
t_err		ft_check_file(char *argv, char ***lines, int *lsrc_c, int *total);
t_err		ft_check_lines(char **lines, int *lsrc_count, int *total);
t_ent_type	ft_check_line_type(char *line);
t_err		ft_incr_ent_count(int ent_count[SUM_ENTS], t_ent_type ent_type);
t_err		ft_check_entity_count(int ent_count[SUM_ENTS]);

// check_import.c
t_err		ft_validate_import(char *filename, char ***lines);
bool		ft_isvalid_filename(char *filename);
t_err		ft_import_file(int fd, char ***lines);

// check_buffer.c
t_err		ft_buf_init(t_buf *buf);
void		ft_buf_destroy(t_buf *buf);
void		ft_buf_clear(t_buf *buf);
t_err		ft_buf_double(t_buf *buf);
t_err		ft_buf_read_file(t_buf *buf, int fd);

// check_line.c
void		ft_rm_space(char **line);
bool		ft_isvalid_float(char **line, float min, float max, bool comma);
bool		ft_isvalid_float_block(char **line, float min, float max);
bool		ft_isvalid_rgb_val(char **line, bool comma);
bool		ft_isvalid_rgb_block(char **line);

// check_entity1.c
t_ent_type	ft_check_ambient(char *line);
t_ent_type	ft_check_camera(char *line);
t_ent_type	ft_check_light(char *line);

// check_entity2.c
t_ent_type	ft_check_sphere(char *line);
t_ent_type	ft_check_plane(char *line);
t_ent_type	ft_check_cylinder(char *line);

// check_error.c
void		ft_perror_count(t_ent_type type, int max, int count, bool high);
bool		ft_perror_range(char *line, size_t offset, int min, int max);
bool		ft_perror_convert(char *line, bool is_float);
bool		ft_perror_separator(char *line, bool comma);
t_ent_type	ft_perror_end(char *line);

#endif