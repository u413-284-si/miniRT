/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_cam_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:10:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 13:43:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_put_cam(t_putinfo put, t_cam cam)
{
	ft_put_str(put, "Centre");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(put, cam.centre);
	ft_put_str(put, "View Direction");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_unit_vec(put, cam.direction);
	ft_put_str(put, "FOV");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(put, ft_radian_to_degree(cam.hfov));
}

void	ft_put_ambient(t_putinfo put, t_light ambient)
{
	put.pos = ft_put_id(put, 0);
	put.pos = ft_put_type(put, AMBIENT);
	ft_put_str(put, "Brightness");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(put, ambient.ratio);
	ft_put_str(put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(put, ambient.colour);
}

void	ft_put_light(t_putinfo put, t_light light)
{
	put.pos = ft_put_id(put, light.id);
	put.pos = ft_put_type(put, LIGHT);
	ft_put_str(put, "Position");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(put, light.pos);
	ft_put_str(put, "Brightness");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(put, light.ratio);
	ft_put_str(put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(put, light.colour);
}
