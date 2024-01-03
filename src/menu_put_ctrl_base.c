/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:21:05 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/03 14:56:44 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_move(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, char *name)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Move ");
	pos.x += 40;
	ft_mlx_put_str(mlx_ptrs, pos, col, name);
	pos.x -= 40;
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  W A S D Q E");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_ctrl_rot(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, char *name)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Rotate ");
	pos.x += 55;
	ft_mlx_put_str(mlx_ptrs, pos, col, name);
	pos.x -= 55;
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  Arrow keys");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_ctrl_inc_dec_1(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, char *name)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Inc/Dec ");
	pos.x += 60;
	ft_mlx_put_str(mlx_ptrs, pos, col, name);
	pos.x -= 60;
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  R F");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_ctrl_inc_dec_2(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, char *name)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Inc/Dec ");
	pos.x += 60;
	ft_mlx_put_str(mlx_ptrs, pos, col, name);
	pos.x -= 60;
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  T G");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

