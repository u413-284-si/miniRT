/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_cam_light_ctrl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:56:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/13 11:28:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_ctrl_cam(t_putinfo put)
{
	put.pos = ft_put_str_and_advance(put, "Controls");
	put.pos.y += Y_HALF_LINE;
	put.pos = ft_put_ctrl_move(put, "centre");
	put.pos = ft_put_ctrl_rot(put, "view");
	put.pos = ft_put_ctrl_inc_dec(put, "FOV", true);
	put.pos.y += Y_NEXT_LINE_BIG;
	put.pos = ft_put_str_and_advance(put, "Rotate view");
	put.pos = ft_put_str_and_advance(put, "(Mode independent)");
	put.pos = ft_put_str_and_advance(put, "  Right mouse and move");
	put.pos.y += Y_HALF_LINE;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_light(t_putinfo put, uint32_t active)
{
	put.pos = ft_put_str_and_advance(put, "Controls");
	if (active == 0)
		put.pos = ft_put_type(put, AMBIENT);
	else
	{
		put.pos = ft_put_type(put, LIGHT);
		put.pos = ft_put_ctrl_move(put, "position");
	}
	put.pos = ft_put_ctrl_inc_dec(put, "brightness", true);
	put.pos = ft_put_ctrl_colour(put);
	put.pos = ft_put_ctrl_change_ent(put, "Light");
	return (put.pos);
}
