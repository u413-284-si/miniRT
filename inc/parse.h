/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:03:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/12 17:50:41 by gwolf            ###   ########.fr       */
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

void	ft_skip_space(char **str);

t_err	ft_parse_file(char *filename, t_entities *entities);

void	ft_parse_ambient(char *line, t_light *ambient);
void	ft_parse_camera(char *line, t_light *test);
void	ft_parse_light(const char *line, t_light *light);
void	ft_parse_sphere(char *line);
void	ft_parse_plane(char *line);
void	ft_parse_cylinder(char *line);

#endif