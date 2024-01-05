/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_ctrl_hittable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:09:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 13:35:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_ctrl_hittable(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_hittable *hittable)
{
	pos = ft_put_id(mlx_ptrs, pos, col, hittable->id);
	pos = ft_put_type(mlx_ptrs, pos, col, hittable->type);
	if (hittable->type == SPHERE)
		pos = ft_put_ctrl_sp(mlx_ptrs, pos, col);
	else if (hittable->type == PLANE)
		pos = ft_put_ctrl_pl(mlx_ptrs, pos, col);
	else if (hittable->type == CYLINDER)
		pos = ft_put_ctrl_cy(mlx_ptrs, pos, col);
	return (pos);
}

t_vec2i	ft_put_ctrl_sp(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col)
{
	pos = ft_put_ctrl_move(mlx_ptrs, pos, col, "sphere");
	pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, pos, col, "Diameter");
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Colour");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  1 - 9");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Object");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  N M");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_ctrl_pl(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col)
{
	pos = ft_put_ctrl_move(mlx_ptrs, pos, col, "point");
	pos = ft_put_ctrl_rot(mlx_ptrs, pos, col, "normal");
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Colour");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  1 - 9");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Object");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  N M");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_ctrl_cy(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col)
{
	pos = ft_put_ctrl_move(mlx_ptrs, pos, col, "centre");
	pos = ft_put_ctrl_rot(mlx_ptrs, pos, col, "normal");
	pos = ft_put_ctrl_inc_dec_1(mlx_ptrs, pos, col, "Diameter");
	pos = ft_put_ctrl_inc_dec_2(mlx_ptrs, pos, col, "Height");
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Colour");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  1 - 9");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Change Object");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "  N M");
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}
