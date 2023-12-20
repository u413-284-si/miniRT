/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:26:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/20 11:30:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdio.h>

// Home-grown libs
# include "vec3.h"
# include "mat4.h"
# include "colour.h"
# include "entities.h"

/* ====== FUNCTIONS ====== */

// print_structs.c
void	ft_print_vec3(const t_vec3 vec);
void	ft_print_mat4(const t_mat4 mat);
void	ft_print_colour(const t_colour colour);

// print_entity.c
void	ft_print_sphere(const t_sphere sp);
void	ft_print_plane(const t_plane pl);
void	ft_print_cylinder(const t_cylinder cy);

#endif
