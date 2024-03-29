/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_utils_ctrl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:21:05 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/13 08:12:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_ctrl_move(t_putinfo put, char *name)
{
	ft_put_str(put, "Move ");
	put.pos.x += 40;
	ft_put_str(put, name);
	put.pos.x -= 40;
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  W A S D Q E");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_rot(t_putinfo put, char *name)
{
	ft_put_str(put, "Rotate ");
	put.pos.x += 55;
	ft_put_str(put, name);
	put.pos.x -= 55;
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  Arrow keys");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_inc_dec(t_putinfo put, char *name, bool first)
{
	ft_put_str(put, "Inc/Dec ");
	put.pos.x += 60;
	ft_put_str(put, name);
	put.pos.x -= 60;
	put.pos.y += Y_NEXT_LINE;
	if (first)
		ft_put_str(put, "  R F");
	else
		ft_put_str(put, "  T G");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_colour(t_putinfo put)
{
	ft_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_change_ent(t_putinfo put, char *name)
{
	ft_put_str(put, "Change");
	put.pos.x += 55;
	ft_put_str(put, name);
	put.pos.x -= 55;
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
