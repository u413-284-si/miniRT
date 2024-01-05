/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:55:32 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:31:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_hittable hittable)
{
	put.pos = ft_put_id(mlx_ptrs, put, hittable.id);
	put.pos = ft_put_type(mlx_ptrs, put, hittable.type);
	if (hittable.type == SPHERE)
		ft_put_sphere(mlx_ptrs, put, hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_put_plane(mlx_ptrs, put, hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_put_cylinder(mlx_ptrs, put, hittable.params.cy);
}

void	ft_put_sphere(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
						t_sphere sp)
{
	ft_mlx_put_str(mlx_ptrs, put, "Centre");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(mlx_ptrs, put, sp.centre);
	ft_mlx_put_str(mlx_ptrs, put, "Diameter");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(mlx_ptrs, put, sp.r);
	ft_mlx_put_str(mlx_ptrs, put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(mlx_ptrs, put, sp.colour);
}

void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
						t_plane pl)
{
	ft_mlx_put_str(mlx_ptrs, put, "Point");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(mlx_ptrs, put, pl.point);
	ft_mlx_put_str(mlx_ptrs, put, "Normal");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_unit_vec(mlx_ptrs, put, pl.normal);
	ft_mlx_put_str(mlx_ptrs, put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(mlx_ptrs, put, pl.colour);
}

void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
							t_cylinder cy)
{
	ft_mlx_put_str(mlx_ptrs, put, "Centre");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(mlx_ptrs, put, cy.centre);
	ft_mlx_put_str(mlx_ptrs, put, "Axis");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_unit_vec(mlx_ptrs, put, cy.axis);
	ft_mlx_put_str(mlx_ptrs, put, "Diameter");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(mlx_ptrs, put, cy.d);
	ft_mlx_put_str(mlx_ptrs, put, "Height");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(mlx_ptrs, put, cy.h);
	ft_mlx_put_str(mlx_ptrs, put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_colour(mlx_ptrs, put, cy.colour);
}
