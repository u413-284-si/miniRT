/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_hittable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:59:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_hittable(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_hittable *hittable)
{
	put.pos = ft_put_id(mlx_ptrs, put, hittable->id);
	put.pos = ft_put_type(mlx_ptrs, put, hittable->type);
	if (hittable->type == SPHERE)
		put.pos = ft_put_ctrl_sp(mlx_ptrs, put);
	else if (hittable->type == PLANE)
		put.pos = ft_put_ctrl_pl(mlx_ptrs, put);
	else if (hittable->type == CYLINDER)
		put.pos = ft_put_ctrl_cy(mlx_ptrs, put);
	return (put.pos);
}

t_vec2i	ft_put_ctrl_sp(t_mlx_ptrs *mlx_ptrs, t_putinfo put)
{
	put.pos = ft_put_ctrl_move(mlx_ptrs, put, "sphere");
	put.pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, put, "Diameter");
	ft_mlx_put_str(mlx_ptrs, put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_pl(t_mlx_ptrs *mlx_ptrs, t_putinfo put)
{
	put.pos = ft_put_ctrl_move(mlx_ptrs, put, "point");
	put.pos = ft_put_ctrl_rot(mlx_ptrs, put, "normal");
	ft_mlx_put_str(mlx_ptrs, put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_cy(t_mlx_ptrs *mlx_ptrs, t_putinfo put)
{
	put.pos = ft_put_ctrl_move(mlx_ptrs, put, "centre");
	put.pos = ft_put_ctrl_rot(mlx_ptrs, put, "normal");
	put.pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, put, "Diameter");
	put.pos = ft_put_ctrl_inc_dec_2(mlx_ptrs, put, "Height");
	ft_mlx_put_str(mlx_ptrs, put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, put, "Change Object");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  N M");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
