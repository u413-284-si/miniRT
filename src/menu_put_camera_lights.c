/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_camera_lights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:10:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:55:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_cam cam)
{
	ft_mlx_put_str(mlx_ptrs, put, "Centre");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(mlx_ptrs, put, cam.centre);
	ft_mlx_put_str(mlx_ptrs, put, "View Direction");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_unit_vec(mlx_ptrs, put, cam.direction);
	ft_mlx_put_str(mlx_ptrs, put, "FOV");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(mlx_ptrs, put, ft_radian_to_degree(cam.hfov));
}

void	ft_put_ambient(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_light ambient)
{
	put.pos = ft_put_id(mlx_ptrs, put, 0);
	put.pos = ft_put_type(mlx_ptrs, put, AMBIENT);
	ft_mlx_put_str(mlx_ptrs, put, "Brightness");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(mlx_ptrs, put, ambient.ratio);
	ft_mlx_put_str(mlx_ptrs, put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(mlx_ptrs, put, ambient.colour);
}

void	ft_put_light(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_light light)
{
	put.pos = ft_put_id(mlx_ptrs, put, light.id);
	put.pos = ft_put_type(mlx_ptrs, put, LIGHT);
	ft_mlx_put_str(mlx_ptrs, put, "Position");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_3d_point(mlx_ptrs, put, light.pos);
	ft_mlx_put_str(mlx_ptrs, put, "Brightness");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_float_value(mlx_ptrs, put, light.ratio);
	ft_mlx_put_str(mlx_ptrs, put, "Colour");
	put.pos.y += Y_NEXT_LINE;
	put.pos = ft_put_colour(mlx_ptrs, put, light.colour);
}
