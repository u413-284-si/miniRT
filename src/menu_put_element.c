/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:16:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/30 16:18:05 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
							t_vec3 point)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET;

	numinfo.pad = 5;
	numinfo.prec = 2;
	numinfo.col = col;
	ft_mlx_put_str(mlx_ptrs, pos, col, " x:");
	numinfo.numf = point.x;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, " y:");
	numinfo.numf = point.y;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, " z:");
	numinfo.numf = point.z;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
							t_vec3 vec)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET;

	numinfo.pad = 2;
	numinfo.prec = 5;
	numinfo.col = col;
	ft_mlx_put_str(mlx_ptrs, pos, col, " x:");
	numinfo.numf = vec.x;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, " y:");
	numinfo.numf = vec.y;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, " z:");
	numinfo.numf = vec.z;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_colour colour)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET_BIG;

	numinfo.pad = 3;
	numinfo.col = col;
	ft_mlx_put_str(mlx_ptrs, pos, col, " r:");
	numinfo.numi = colour.r * 255.99;
	ft_mlx_put_int(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, " g:");
	numinfo.numi = colour.g * 255.99;
	ft_mlx_put_int(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, " b:");
	numinfo.numi = colour.b * 255.99;
	ft_mlx_put_int(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_float_value(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
							float value)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET;

	numinfo.pad = 5;
	numinfo.prec = 2;
	numinfo.col = col;
	numinfo.numf = value;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}
