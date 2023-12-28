/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:16:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/28 08:56:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_vec3 point, char *name)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET;

	numinfo.pad = 5;
	numinfo.prec = 2;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, name);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = point.x;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " x:");
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = point.y;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " y:");
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = point.z;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " z:");
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_ELEM_SPACE;
	return (pos);
}

t_vec2i	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_vec3 vec, char *name)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET;

	numinfo.pad = 2;
	numinfo.prec = 5;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, name);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = vec.x;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " x:");
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = vec.y;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " y:");
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = vec.z;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " z:");
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_ELEM_SPACE;
	return (pos);
}

t_vec2i	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_colour colour)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET_BIG;

	numinfo.pad = 3;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, "Colour");
	pos.y += Y_NEXT_LINE;
	numinfo.numi = colour.r * 255;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " r:");
	ft_mlx_put_int(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	numinfo.numi = colour.g * 255;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " g:");
	ft_mlx_put_int(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_NEXT_LINE;
	numinfo.numi = colour.b * 255;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, " b:");
	ft_mlx_put_int(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_ELEM_SPACE;
	return (pos);
}

t_vec2i	ft_put_float_value(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, float value, char *name)
{
	t_numinfo	numinfo;
	const int	num_x = pos.x + X_OFFSET;

	numinfo.pad = 5;
	numinfo.prec = 2;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, WHITE, name);
	pos.y += Y_NEXT_LINE;
	numinfo.numf = value;
	ft_mlx_put_float(mlx_ptrs, (t_vec2i){num_x, pos.y}, numinfo);
	pos.y += Y_ELEM_SPACE;
	return (pos);
}
