/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_cam_lights.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:56:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/03 18:09:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_cam(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col)
{
	pos = ft_put_ctrl_move(mlx_ptrs, pos, col, "centre");
	pos = ft_put_ctrl_rot(mlx_ptrs, pos, col, "view");
	pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, pos, col, "FOV");
	return (pos);
}

t_vec2i	ft_put_ctrl_light(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, uint32_t active)
{
	if (active == 0)
	{
		ft_mlx_put_str(mlx_ptrs, pos, col, "Ambient Light");
		pos.y += Y_NEXT_LINE_BIG;
	}
	else
		pos = ft_put_ctrl_move(mlx_ptrs, pos, col, "position");
	pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, pos, col, "brightness");
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Colour");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  1 - 9");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Light");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  N M");
	return (pos);
}
