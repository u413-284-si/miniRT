/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:16:08 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:44:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_vec3 point)
{
	t_numinfo	numinfo;
	const int	num_x = put.pos.x + 30;

	numinfo.pad = 5;
	numinfo.prec = 2;
	ft_mlx_put_str(mlx_ptrs, put, " x:");
	numinfo.numf = point.x;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, " y:");
	numinfo.numf = point.y;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, " z:");
	numinfo.numf = point.z;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_vec3 vec)
{
	t_numinfo	numinfo;
	const int	num_x = put.pos.x + 30;

	numinfo.pad = 2;
	numinfo.prec = 5;
	ft_mlx_put_str(mlx_ptrs, put, " x:");
	numinfo.numf = vec.x;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, " y:");
	numinfo.numf = vec.y;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, " z:");
	numinfo.numf = vec.z;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_colour colour)
{
	t_numinfo	numinfo;
	const int	num_x = put.pos.x + 70;

	numinfo.pad = 3;
	ft_mlx_put_str(mlx_ptrs, put, " r:");
	numinfo.numi = colour.r * 255.99;
	ft_mlx_put_int(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, " g:");
	numinfo.numi = colour.g * 255.99;
	ft_mlx_put_int(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, " b:");
	numinfo.numi = colour.b * 255.99;
	ft_mlx_put_int(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_float_value(t_mlx_ptrs *mlx_ptrs, t_putinfo put, float value)
{
	t_numinfo	numinfo;
	const int	num_x = put.pos.x + 30;

	numinfo.pad = 5;
	numinfo.prec = 2;
	numinfo.numf = value;
	ft_mlx_put_float(mlx_ptrs, (t_putinfo){.pos.x = num_x, .pos.y = put.pos.y,
		.col = put.col}, numinfo);
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
