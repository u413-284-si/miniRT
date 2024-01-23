/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable_ctrl_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:58:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/22 17:00:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

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
	else if (type == CONE)
		put.pos = ft_put_ctrl_co(put);
	return (put.pos);
}

t_vec2i	ft_put_ctrl_co(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "Apex");
	put.pos = ft_put_ctrl_rot(put, "Normal");
	put.pos = ft_put_ctrl_inc_dec(put, "Diameter", true);
	put.pos = ft_put_ctrl_inc_dec(put, "Height", false);
	put.pos = ft_put_ctrl_colour(put);
	put.pos = ft_put_ctrl_change_ent(put, "Object");
	return (put.pos);
}

