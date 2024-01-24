/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:55:32 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 16:54:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

#ifndef IS_BONUS
void	ft_put_hittable(t_putinfo put, t_hittable hittable, int total)
{
	put.pos = ft_put_id(put, hittable.id, total);
	put.pos = ft_put_type(put, hittable.type);
	if (hittable.type == SPHERE)
		ft_put_sp(put, hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_put_pl(put, hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_put_cy(put, hittable.params.cy);
}
#endif

void	ft_put_sp(t_putinfo put, t_sphere sp)
{
	put.pos = ft_put_3d_point("Centre", put, sp.centre);
	put.pos = ft_put_single_float_value("Radius", put, sp.r);
	put.pos = ft_put_colour(put, sp.colour);
}

void	ft_put_pl(t_putinfo put, t_plane pl)
{
	put.pos = ft_put_3d_point("Point", put, pl.point);
	put.pos = ft_put_unit_vec("Normal", put, pl.normal);
	put.pos = ft_put_colour(put, pl.colour);
}

void	ft_put_cy(t_putinfo put, t_cylinder cy)
{
	put.pos = ft_put_3d_point("Centre", put, cy.centre);
	put.pos = ft_put_unit_vec("Axis", put, cy.axis);
	put.pos = ft_put_single_float_value("Diameter", put, cy.r * 2);
	put.pos = ft_put_single_float_value("Height", put, cy.h);
	put.pos = ft_put_colour(put, cy.colour);
}
