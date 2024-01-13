/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_cam_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:10:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/13 11:01:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_put_cam(t_putinfo put, t_cam cam)
{
	put.pos = ft_put_3d_point("Centre", put, cam.centre);
	put.pos = ft_put_unit_vec("View direction", put, cam.direction);
	put.pos = ft_put_single_float_value("FOV", put,
			ft_radian_to_degree(cam.hfov));
}

void	ft_put_ambient(t_putinfo put, t_light ambient, int total)
{
	put.pos = ft_put_id(put, 0, total);
	put.pos = ft_put_type(put, AMBIENT);
	put.pos = ft_put_single_float_value("Brightness", put, ambient.ratio);
	put.pos = ft_put_colour(put, ambient.colour);
}

void	ft_put_light(t_putinfo put, t_light light, int total)
{
	put.pos = ft_put_id(put, light.id, total);
	if (light.id == 0)
		put.pos = ft_put_type(put, AMBIENT);
	else
	{
		put.pos = ft_put_type(put, LIGHT);
		put.pos = ft_put_3d_point("Position", put, light.pos);
	}
	put.pos = ft_put_single_float_value("Brightness", put, light.ratio);
	put.pos = ft_put_colour(put, light.colour);
}
