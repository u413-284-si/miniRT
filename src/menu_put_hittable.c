/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:55:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/30 16:56:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
							t_hittable hittable)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, BOLD);
	ft_mlx_put_str(mlx_ptrs, pos, col, "*** ID:   ***");
	pos.x += 50;
	ft_mlx_put_int(mlx_ptrs, pos,
		(t_numinfo){.numi = hittable.id, .pad = 3, .prec = 0, .col = col});
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	pos.x -= 50;
	pos.y += Y_NEXT_LINE;
	if (hittable.type == SPHERE)
		ft_put_sphere(mlx_ptrs, pos, col, hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_put_plane(mlx_ptrs, pos, col, hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_put_cylinder(mlx_ptrs, pos, col, hittable.params.cy);
}

void	ft_put_sphere(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_sphere sp)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Type: Sphere");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Centre");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_3d_point(mlx_ptrs, pos, col, sp.centre);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Diameter");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, sp.r);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Colour");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_colour(mlx_ptrs, pos, col, sp.colour);
}

void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_plane pl)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Type: Plane");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Point");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_3d_point(mlx_ptrs, pos, col, pl.point);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Normal");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_unit_vec(mlx_ptrs, pos, col, pl.normal);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Colour");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_colour(mlx_ptrs, pos, col, pl.colour);
}

void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
							t_cylinder cy)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Type: Cylinder");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Centre");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_3d_point(mlx_ptrs, pos, col, cy.centre);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Axis");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_unit_vec(mlx_ptrs, pos, col, cy.axis);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Diameter");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, cy.d);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Height");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, cy.h);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Colour");
	pos.y += Y_NEXT_LINE;
	ft_put_colour(mlx_ptrs, pos, col, cy.colour);
}
