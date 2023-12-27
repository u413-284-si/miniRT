/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:55:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 17:08:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_hittable hittable)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "ID:");
	pos.x += 20;
	ft_mlx_put_int(mlx_ptrs, pos, (t_numinfo){.numi = hittable.id, .pad = 3, .prec = 0});
	pos.x -= 20;
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
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Type: Sphere");
	pos.y += 20;
	ft_put_3d_point(mlx_ptrs, pos, sp.centre, "Centre");
	pos.y += 80;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Diameter");
	pos.y += 20;
	ft_mlx_put_float(mlx_ptrs, pos, (t_numinfo){.numf = sp.r, .pad = 3, .prec = 2});
	pos.y += 20;
	ft_put_colour(mlx_ptrs, pos, sp.colour);
}

void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_plane pl)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Type: Plane");
	pos.y += 20;
	ft_put_3d_point(mlx_ptrs, pos, pl.point, "Point");
	pos.y += 80;
	ft_put_unit_vec(mlx_ptrs, pos, pl.normal, "Normal");
	pos.y += 80;
	ft_put_colour(mlx_ptrs, pos, pl.colour);
}

void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_cylinder cy)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Type: Cylinder");
	pos.y += 20;
	ft_put_3d_point(mlx_ptrs, pos, cy.centre, "Centre");
	pos.y += 80;
	ft_put_unit_vec(mlx_ptrs, pos, cy.axis, "Axis");
	pos.y += 80;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Diameter");
	pos.y += 20;
	ft_mlx_put_float(mlx_ptrs, pos, (t_numinfo){.numf = cy.d, .pad = 3, .prec = 2});
	pos.y += 20;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Height");
	pos.y += 20;
	ft_mlx_put_float(mlx_ptrs, pos, (t_numinfo){.numf = cy.h, .pad = 3, .prec = 2});
	pos.y += 20;
	ft_put_colour(mlx_ptrs, pos, cy.colour);
}
