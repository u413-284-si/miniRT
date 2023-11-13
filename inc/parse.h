/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:03:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 18:21:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* ====== LIBRARIES ====== */

# include "miniRT_error.h"
# include "scene.h"
# include "cleanup.h"
# include "ft_strtod.h"
# include "camera.h"

/* ====== FUNCTIONS ====== */

// import from check_file.c
t_err	ft_check_file(char *filename, char ***lines, int *lsrc_c, int *total);

// parse_file.c
t_err	ft_parse_file(char *filename, t_entities *ents, t_cam *cam);
void	ft_parse_lines(t_entities *ents, t_cam *cam, char **lines);
t_err	ft_malloc_ents(t_light **lsrc, t_hittable **obj, int lsrc_c, int total);

// parse_entity1.c
void	ft_parse_ambient(char *line, t_light *ambient);
void	ft_parse_camera(char *line, t_cam *cam);
void	ft_parse_light(char *line, t_light *light);

// parse_entity2.c
void	ft_parse_sphere(char *line, t_hittable *sphere, size_t id);
void	ft_parse_plane(char *line, t_hittable *plane, size_t id);
void	ft_parse_cylinder(char *line, t_hittable *cylinder, size_t id);

// parse_line.c
void	ft_parse_colour_block(char **line, t_colour *colour);
void	ft_parse_float(char **line, float *var);
void	ft_parse_float_block(char **line, t_vec3 *vec3);

#endif