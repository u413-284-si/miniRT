/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:21:05 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/31 13:26:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_camera(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Controls");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Move Position");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "W A S D Q E");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Rotate view");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Arrow keys");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change mode");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Ctrl");
	pos.y += Y_NEXT_LINE;
	return (pos);
}
