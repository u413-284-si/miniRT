/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:16:08 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 12:01:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

static t_vec2i	ft_put_coord(char *name, t_putinfo put, t_numinfo numinfo,
					bool is_int)
{
	const int	offset = ft_strlen(name) * 10;

	ft_put_str(put, name);
	put.pos.x += offset;
	if (is_int)
		ft_put_int(put, numinfo);
	else
		ft_put_float(put, numinfo);
	put.pos.x -= offset;
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}

t_vec2i	ft_put_3d_point(char *name, t_putinfo put, t_vec3 point)
{
	t_numinfo	numinfo;

	ft_put_str(put, name);
	put.pos.y += Y_NEXT_LINE;
	numinfo.pad = 5;
	numinfo.prec = 2;
	numinfo.numf = point.x;
	put.pos = ft_put_coord(" x:", put, numinfo, false);
	numinfo.numf = point.y;
	put.pos = ft_put_coord(" y:", put, numinfo, false);
	numinfo.numf = point.z;
	put.pos = ft_put_coord(" z:", put, numinfo, false);
	put.pos.y += Y_HALF_LINE;
	return (put.pos);
}

t_vec2i	ft_put_unit_vec(char *name, t_putinfo put, t_vec3 vec)
{
	t_numinfo	numinfo;

	ft_put_str(put, name);
	put.pos.y += Y_NEXT_LINE;
	numinfo.pad = 2;
	numinfo.prec = 5;
	numinfo.numf = vec.x;
	put.pos = ft_put_coord(" x:", put, numinfo, false);
	numinfo.numf = vec.y;
	put.pos = ft_put_coord(" y:", put, numinfo, false);
	numinfo.numf = vec.z;
	put.pos = ft_put_coord(" z:", put, numinfo, false);
	put.pos.y += Y_HALF_LINE;
	return (put.pos);
}

t_vec2i	ft_put_colour(t_putinfo put, t_colour colour)
{
	t_numinfo	numinfo;

	ft_put_str(put, "Colour");
	numinfo.pad = 3;
	put.pos.y += Y_NEXT_LINE;
	put.pos.x += 10;
	ft_put_str(put, "R:");
	put.pos.x += 20;
	numinfo.numi = colour.r * 255.99;
	ft_put_int(put, numinfo);
	put.pos.x += 30;
	ft_put_str(put, "G:");
	put.pos.x += 20;
	numinfo.numi = colour.g * 255.99;
	ft_put_int(put, numinfo);
	put.pos.x += 30;
	ft_put_str(put, "B:");
	put.pos.x += 20;
	numinfo.numi = colour.b * 255.99;
	ft_put_int(put, numinfo);
	put.pos.x += 40;
	put.pos.y += Y_HALF_LINE;
	return (put.pos);
}

t_vec2i	ft_put_single_float_value(char *name, t_putinfo put, float value)
{
	t_numinfo	numinfo;
	const int	offset = 30;

	ft_put_str(put, name);
	put.pos.y += Y_NEXT_LINE;
	numinfo.pad = 5;
	numinfo.prec = 2;
	numinfo.numf = value;
	put.pos.x += offset;
	ft_put_float(put, numinfo);
	put.pos.x -= offset;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
