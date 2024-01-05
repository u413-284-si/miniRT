/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:54:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:52:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_vec2i	ft_put_mode(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_mode mode)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, BOLD);
	ft_mlx_put_str(mlx_ptrs, put, "Mode:");
	put.pos.x += 50;
	if (mode == CTRL_SCENE)
		ft_mlx_put_str(mlx_ptrs, put, "Scene");
	else if (mode == CTRL_CAM)
		ft_mlx_put_str(mlx_ptrs, put, "Camera");
	else if (mode == CTRL_LIGHT)
		ft_mlx_put_str(mlx_ptrs, put, "Light");
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_type(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_type type)
{
	ft_mlx_put_str(mlx_ptrs, put, "Type:");
	put.pos.x += 50;
	if (type == SPHERE)
		ft_mlx_put_str(mlx_ptrs, put, "Sphere");
	else if (type == PLANE)
		ft_mlx_put_str(mlx_ptrs, put, "Plane");
	else if (type == CYLINDER)
		ft_mlx_put_str(mlx_ptrs, put, "Cylinder");
	else if (type == AMBIENT)
		ft_mlx_put_str(mlx_ptrs, put, "Ambient");
	else if (type == LIGHT)
		ft_mlx_put_str(mlx_ptrs, put, "Light");
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_id(t_mlx_ptrs *mlx_ptrs, t_putinfo put, int id)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, BOLD);
	ft_mlx_put_str(mlx_ptrs, put, "*** ID:   ***");
	put.pos.x += 50;
	ft_mlx_put_int(mlx_ptrs, put, (t_numinfo){.numi = id, .pad = 3, .prec = 0});
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}

t_vec2i	ft_put_info(t_mlx_ptrs *mlx_ptrs, t_putinfo put)
{
	put.pos.x -= 15;
	ft_mlx_put_str(mlx_ptrs, put, "------------------------");
	put.pos.x += 15;
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "Ctrl:  Switch mode");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "Shift: Show controls");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "I:     Close menu");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "P:     Print scene");
	put.pos.y += Y_NEXT_LINE;
	ft_mlx_put_str(mlx_ptrs, put, "ESC:   Exit");
	return (put.pos);
}
