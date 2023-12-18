/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:46:17 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/18 17:36:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include "entities.h"

void	ft_print_vec3(const t_vec3 vec);
void	ft_print_colour(const t_colour col);
void	ft_print_sphere(const t_sphere sphere);
void	ft_print_plane(const t_plane plane);
void	ft_print_cylinder(const t_cylinder cy);


#endif