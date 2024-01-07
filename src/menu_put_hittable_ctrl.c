/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable_ctrl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 14:23:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_ctrl_hittable(t_putinfo put,
			t_hittable hittable)
{
	put.pos = ft_put_id(put, hittable.id);
	put.pos = ft_put_type(put, hittable.type);
	if (hittable.type == SPHERE)
		put.pos = ft_put_ctrl_sp(put);
	else if (hittable.type == PLANE)
		put.pos = ft_put_ctrl_pl(put);
	else if (hittable.type == CYLINDER)
		put.pos = ft_put_ctrl_cy(put);
	return (put.pos);
}

t_vec2i	ft_put_ctrl_sp(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "sphere");
	put.pos = ft_put_ctrl_inc_dec(put, "Diameter", true);
	ft_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_put_str(put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_pl(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "point");
	put.pos = ft_put_ctrl_rot(put, "normal");
	ft_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_put_str(put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_cy(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "centre");
	put.pos = ft_put_ctrl_rot(put, "normal");
	put.pos = ft_put_ctrl_inc_dec(put, "Diameter", true);
	put.pos = ft_put_ctrl_inc_dec(put, "Height", false);
	ft_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_put_str(put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
