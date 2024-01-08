/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_general_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:54:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 14:11:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_mode(t_putinfo put, uint8_t options)
{
	mlx_set_font(put.mlx_ptrs.mlx_ptr, put.mlx_ptrs.win_ptr, BOLD);
	ft_put_str(put, "Mode:");
	put.pos.x += 50;
	if (ft_bit_is_set(options, O_MODE_SCENE))
		ft_put_str(put, "Scene");
	else if (ft_bit_is_set(options, O_MODE_LIGHT))
		ft_put_str(put, "Light");
	else if (ft_bit_is_set(options, O_MODE_CAM))
		ft_put_str(put, "Camera");
	mlx_set_font(put.mlx_ptrs.mlx_ptr, put.mlx_ptrs.win_ptr, REGULAR);
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_type(t_putinfo put, t_type type)
{
	ft_put_str(put, "Type:");
	put.pos.x += 50;
	if (type == SPHERE)
		ft_put_str(put, "Sphere");
	else if (type == PLANE)
		ft_put_str(put, "Plane");
	else if (type == CYLINDER)
		ft_put_str(put, "Cylinder");
	else if (type == AMBIENT)
		ft_put_str(put, "Ambient");
	else if (type == LIGHT)
		ft_put_str(put, "Light");
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_id(t_putinfo put, int id)
{
	mlx_set_font(put.mlx_ptrs.mlx_ptr, put.mlx_ptrs.win_ptr, BOLD);
	ft_put_str(put, "*** ID:   ***");
	put.pos.x += 50;
	ft_put_int(put, (t_numinfo){.numi = id, .pad = 3, .prec = 0});
	mlx_set_font(put.mlx_ptrs.mlx_ptr, put.mlx_ptrs.win_ptr, REGULAR);
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}

t_vec2i	ft_put_info(t_putinfo put)
{
	put.pos = (t_vec2i){X_MENU_OFFSET, Y_MENU_INFO_POS};
	put.pos.x -= 15;
	ft_put_str(put, "------------------------");
	put.pos.x += 15;
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "Ctrl:  Switch mode");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "Shift: Toggle controls");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "I:     Toggle menu");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "P:     Print scene");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "ESC:   Exit");
	return (put.pos);
}
