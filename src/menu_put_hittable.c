/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:55:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/28 08:50:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_hittable hittable)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, BOLD);
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, "*** ID:   ***");
	pos.x += 50;
	ft_mlx_put_int(mlx_ptrs, pos, (t_numinfo){.numi = hittable.id, .pad = 3, .prec = 0});
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	pos.x -= 50;
	pos.y += 20;
	if (hittable.type == SPHERE)
		ft_put_sphere(mlx_ptrs, pos, hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_put_plane(mlx_ptrs, pos, hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_put_cylinder(mlx_ptrs, pos, hittable.params.cy);
}

void	ft_put_sphere(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_sphere sp)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, "Type: Sphere");
	pos.y += Y_ELEM_SPACE;
	pos = ft_put_3d_point(mlx_ptrs, pos, sp.centre, "Centre");
	pos = ft_put_float_value(mlx_ptrs, pos, sp.r, "Diameter");
	pos = ft_put_colour(mlx_ptrs, pos, sp.colour);
}

void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_plane pl)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, "Type: Plane");
	pos.y += Y_ELEM_SPACE;
	pos = ft_put_3d_point(mlx_ptrs, pos, pl.point, "Point");
	pos = ft_put_unit_vec(mlx_ptrs, pos, pl.normal, "Normal");
	pos = ft_put_colour(mlx_ptrs, pos, pl.colour);
}

void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_cylinder cy)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, "Type: Cylinder");
	pos.y += Y_ELEM_SPACE;
	pos = ft_put_3d_point(mlx_ptrs, pos, cy.centre, "Centre");
	pos = ft_put_unit_vec(mlx_ptrs, pos, cy.axis, "Axis");
	pos = ft_put_float_value(mlx_ptrs, pos, cy.d, "Diameter");
	pos = ft_put_float_value(mlx_ptrs, pos, cy.h, "Height");
	ft_put_colour(mlx_ptrs, pos, cy.colour);
}
