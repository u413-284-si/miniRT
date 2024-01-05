/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_cam_lights.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:56:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:58:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_cam(t_mlx_ptrs *mlx_ptrs, t_putinfo put)
{
	put.pos = ft_put_ctrl_move(mlx_ptrs, put, "centre");
	put.pos = ft_put_ctrl_rot(mlx_ptrs, put, "view");
	put.pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, put, "FOV");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, put, "Rotate view");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "(Mode independent)");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  Right mouse and move");
	put.pos.y += Y_NEXT_LINE_BIG;

	return (put.pos);
}

t_vec2i	ft_put_ctrl_light(t_mlx_ptrs *mlx_ptrs, t_putinfo put, uint32_t active)
{
	put.pos = ft_put_id(mlx_ptrs, put, active);
	if (active == 0)
		put.pos = ft_put_type(mlx_ptrs, put, AMBIENT);
	else
	{
		put.pos = ft_put_type(mlx_ptrs, put, LIGHT);
		put.pos = ft_put_ctrl_move(mlx_ptrs, put, "position");
	}
	put.pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, put, "brightness");
	ft_mlx_put_str(mlx_ptrs, put, "Change Colour");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  1 - 9");
	put.pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, put, "Change Light");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  N M");
	return (put.pos);
}
