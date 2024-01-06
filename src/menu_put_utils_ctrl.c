/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_utils_ctrl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:21:05 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 13:42:59 by gwolf            ###   ########.fr       */
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

t_vec2i	ft_put_ctrl_inc_dec_1(t_putinfo put, char *name)
{
	ft_put_str(put, "Inc/Dec ");
	put.pos.x += 60;
	ft_put_str(put, name);
	put.pos.x -= 60;
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  R F");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_inc_dec_2(t_putinfo put, char *name)
{
	ft_put_str(put, "Inc/Dec ");
	put.pos.x += 60;
	ft_put_str(put, name);
	put.pos.x -= 60;
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "  T G");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

