/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_hittable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 12:22:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

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
	put.pos = ft_put_ctrl_inc_dec_1(put, "Diameter");
	ft_mlx_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_pl(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "point");
	put.pos = ft_put_ctrl_rot(put, "normal");
	ft_mlx_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_cy(t_putinfo put)
{
	put.pos = ft_put_ctrl_move(put, "centre");
	put.pos = ft_put_ctrl_rot(put, "normal");
	put.pos = ft_put_ctrl_inc_dec_1(put, "Diameter");
	put.pos = ft_put_ctrl_inc_dec_2(put, "Height");
	ft_mlx_put_str(put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
