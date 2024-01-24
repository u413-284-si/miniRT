/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable_ctrl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 16:57:40 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

#ifndef IS_BONUS
t_vec2i	ft_put_ctrl_hittable(t_putinfo put, t_type type)
{
	put.pos = ft_put_str_and_advance(put, "Controls");
	put.pos = ft_put_type(put, type);
	if (type == SPHERE)
		put.pos = ft_put_ctrl_sp(put);
	else if (type == PLANE)
		put.pos = ft_put_ctrl_pl(put);
	else if (type == CYLINDER)
		put.pos = ft_put_ctrl_cy(put);
	return (put.pos);
}
#endif

t_vec2i	ft_put_ctrl_sp(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "sphere");
	put.pos = ft_put_ctrl_inc_dec(put, "Diameter", true);
	put.pos = ft_put_ctrl_colour(put);
	put.pos = ft_put_ctrl_change_ent(put, "Object");
	return (put.pos);
}

t_vec2i	ft_put_ctrl_pl(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "point");
	put.pos = ft_put_ctrl_rot(put, "normal");
	put.pos = ft_put_ctrl_colour(put);
	put.pos = ft_put_ctrl_change_ent(put, "Object");
	return (put.pos);
}

t_vec2i	ft_put_ctrl_cy(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "centre");
	put.pos = ft_put_ctrl_rot(put, "normal");
	put.pos = ft_put_ctrl_inc_dec(put, "Diameter", true);
	put.pos = ft_put_ctrl_inc_dec(put, "Height", false);
	put.pos = ft_put_ctrl_colour(put);
	put.pos = ft_put_ctrl_change_ent(put, "Object");
	return (put.pos);
}
