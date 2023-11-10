/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:37:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/10 19:14:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

/* ====== LIBRARIES ====== */

#include "miniRT_error.h"
#include "ft_char.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

// check_file.c
bool	ft_check_filename(char *argv);
void	ft_check_file(char *argv);
t_err	ft_import_file(int fd, char ***lines);
t_err	ft_check_line(char **lines);
bool	ft_is_valid_line(char *line);

// check_line.c
void	ft_skip_space(char **line);
bool	ft_is_valid_float(char **line);
bool	ft_is_valid_float_block(char **line);
bool	ft_is_valid_rgb_val(char **line);
bool	ft_is_valid_rgb_block(char **line);

// check_entity1.c
bool	ft_check_ambient(char *line);
bool	ft_check_camera(char *line);
bool	ft_check_light(char *line);

// check_entity2.c
bool	ft_check_sphere(char *line);
bool	ft_check_plane(char *line);
bool	ft_check_cylinder(char *line);

#endif