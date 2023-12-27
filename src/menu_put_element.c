/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dashboard_put_element.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:16:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 15:42:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dashboard.h"

void	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_vec3 point, char *name)
{
	t_numinfo	numinfo;

	numinfo.pad = 0;
	numinfo.prec = 2;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, name);
	pos.y += 20;
	pos.x += 20;
	numinfo.numf = point.x;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "x:");
	ft_mlx_put_float(mlx_ptrs, pos, numinfo);
	pos.y += 20;
	numinfo.numf = point.y;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "y:");
	ft_mlx_put_float(mlx_ptrs, pos, numinfo);
	pos.y += 20;
	numinfo.numf = point.z;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "z:");
	ft_mlx_put_float(mlx_ptrs, pos, numinfo);
}

void	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_vec3 vec, char *name)
{
	t_numinfo	numinfo;

	numinfo.pad = 2;
	numinfo.prec = 6;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, name);
	pos.y += 20;
	pos.x += 20;
	numinfo.numf = vec.x;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "x:");
	ft_mlx_put_float(mlx_ptrs, pos, numinfo);
	pos.y += 20;
	numinfo.numf = vec.y;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "y:");
	ft_mlx_put_float(mlx_ptrs, pos, numinfo);
	pos.y += 20;
	numinfo.numf = vec.z;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "z:");
	ft_mlx_put_float(mlx_ptrs, pos, numinfo);
}

void	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_colour colour)
{
	t_numinfo	numinfo;

	numinfo.pad = 3;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Colour");
	pos.y += 20;
	pos.x += 20;
	numinfo.numi = colour.r * 255;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "r:");
	ft_mlx_put_int(mlx_ptrs, pos, numinfo);
	pos.y += 20;
	numinfo.numi = colour.g * 255;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "g:");
	ft_mlx_put_int(mlx_ptrs, pos, numinfo);
	pos.y += 20;
	numinfo.numi = colour.b * 255;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x - 20, pos.y, 0x0, "b:");
	ft_mlx_put_int(mlx_ptrs, pos, numinfo);
}
