/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:55:32 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 12:21:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_hittable(t_putinfo put, t_hittable hittable)
{
	put.pos = ft_put_id(put, hittable.id);
	put.pos = ft_put_type(put, hittable.type);
	if (hittable.type == SPHERE)
		ft_put_sphere(put, hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_put_plane(put, hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_put_cylinder(put, hittable.params.cy);
}

void	ft_put_sphere(t_putinfo put, t_sphere sp)
{
	ft_mlx_put_str(put, "Centre");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(put, sp.centre);
	ft_mlx_put_str(put, "Diameter");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(put, sp.r);
	ft_mlx_put_str(put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(put, sp.colour);
}

void	ft_put_plane(t_putinfo put, t_plane pl)
{
	ft_mlx_put_str(put, "Point");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(put, pl.point);
	ft_mlx_put_str(put, "Normal");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_unit_vec(put, pl.normal);
	ft_mlx_put_str(put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(put, pl.colour);
}

void	ft_put_cylinder(t_putinfo put, t_cylinder cy)
{
	ft_mlx_put_str(put, "Centre");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(put, cy.centre);
	ft_mlx_put_str(put, "Axis");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_unit_vec(put, cy.axis);
	ft_mlx_put_str(put, "Diameter");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(put, cy.d);
	ft_mlx_put_str(put, "Height");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(put, cy.h);
	ft_mlx_put_str(put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_colour(put, cy.colour);
}
