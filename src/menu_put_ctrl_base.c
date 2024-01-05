/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:21:05 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:56:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_move(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name)
{
	ft_mlx_put_str(mlx_ptrs, put, "Move ");
	put.pos.x += 40;
	ft_mlx_put_str(mlx_ptrs, put, name);
	put.pos.x -= 40;
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  W A S D Q E");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_rot(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name)
{
	ft_mlx_put_str(mlx_ptrs, put, "Rotate ");
	put.pos.x += 55;
	ft_mlx_put_str(mlx_ptrs, put, name);
	put.pos.x -= 55;
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  Arrow keys");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_inc_dec_1(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name)
{
	ft_mlx_put_str(mlx_ptrs, put, "Inc/Dec ");
	put.pos.x += 60;
	ft_mlx_put_str(mlx_ptrs, put, name);
	put.pos.x -= 60;
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  R F");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_ctrl_inc_dec_2(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name)
{
	ft_mlx_put_str(mlx_ptrs, put, "Inc/Dec ");
	put.pos.x += 60;
	ft_mlx_put_str(mlx_ptrs, put, name);
	put.pos.x -= 60;
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "  T G");
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

