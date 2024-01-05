/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:54:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 13:40:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_mode(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
					t_mode mode)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, BOLD);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Mode:");
	pos.x += X_OFFSET_MID;
	if (mode == CTRL_SCENE)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Scene");
	else if (mode == CTRL_CAM)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Camera");
	else if (mode == CTRL_LIGHT)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Light");
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	pos.x -= X_OFFSET_MID;
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_type(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
					t_type type)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Type:");
	pos.x += X_OFFSET_MID;
	if (type == SPHERE)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Sphere");
	else if (type == PLANE)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Plane");
	else if (type == CYLINDER)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Cylinder");
	else if (type == AMBIENT)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Ambient");
	else if (type == LIGHT)
		ft_mlx_put_str(mlx_ptrs, pos, col, "Light");
	pos.x -= X_OFFSET_MID;
	pos.y += Y_NEXT_LINE_BIG;
	return (pos);
}

t_vec2i	ft_put_id(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, int id)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, BOLD);
	ft_mlx_put_str(mlx_ptrs, pos, col, "*** ID:   ***");
	pos.x += 50;
	ft_mlx_put_int(mlx_ptrs, pos,
		(t_numinfo){.numi = id, .pad = 3, .prec = 0, .col = col});
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	pos.x -= 50;
	pos.y += Y_NEXT_LINE;
	return (pos);
}

t_vec2i	ft_put_info(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col)
{
	pos.x -= 15;
	ft_mlx_put_str(mlx_ptrs, pos, col, "------------------------");
	pos.x += 15;
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Ctrl:  Switch mode");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Shift: Show controls");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "I:     Close menu");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "P:     Print scene");
	pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, pos, col, "ESC:   Exit");
	return (pos);
}
