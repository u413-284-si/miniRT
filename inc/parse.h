/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:03:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 12:17:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* ====== LIBRARIES ====== */

# include "miniRT_error.h"
# include "scene.h"
# include "cleanup.h"
# include "ft_num.h"

/* ====== FUNCTIONS ====== */

double	ft_strtod(const char *str, size_t *offset);

t_err	ft_parse_file(char *filename, t_entities *entities);

void	ft_parse_ambient(char *line, t_light *ambient);
void	ft_parse_camera(char *line, t_light *test);
void	ft_parse_light(const char *line, t_light *light);
void	ft_parse_sphere(char *line, t_hittable *sphere, size_t id);
void	ft_parse_plane(char *line, t_hittable *plane, size_t id);
void	ft_parse_cylinder(char *line, t_hittable *cylinder, size_t id);

void	ft_parse_colour_block(char **line, t_colour *colour);
void	ft_parse_float(char **line, float *var);
void	ft_parse_float_block(char **line, t_vec3 *vec3);

#endif