/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_cam_light_ctrl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:56:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 19:10:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_ctrl_cam(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "centre");
	put.pos = ft_put_ctrl_rot(put, "view");
	put.pos = ft_put_ctrl_inc_dec(put, "FOV", true);
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_put_str(put, "Rotate view");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "(Mode independent)");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  Right mouse and move");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_light(t_putinfo put, uint32_t active)
{
	put.pos = ft_put_id(put, active);
	if (active == 0)
		put.pos = ft_put_type(put, AMBIENT);
	else
	{
		put.pos = ft_put_type(put, LIGHT);
		put.pos = ft_put_ctrl_move(put, "position");
	}
	put.pos = ft_put_ctrl_inc_dec(put, "brightness", true);
	ft_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_put_str(put, "Change Light");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  N M");
	return (put.pos);
}
