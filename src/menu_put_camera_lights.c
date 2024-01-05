/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_camera_lights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:10:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 13:46:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_cam cam)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Centre");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_3d_point(mlx_ptrs, pos, col, cam.centre);
	ft_mlx_put_str(mlx_ptrs, pos, col, "View Direction");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_unit_vec(mlx_ptrs, pos, col, cam.direction);
	ft_mlx_put_str(mlx_ptrs, pos, col, "FOV");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, ft_radian_to_degree(cam.hfov));
}

void	ft_put_ambient(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_light ambient)
{
	pos = ft_put_id(mlx_ptrs, pos, col, 0);
	pos = ft_put_type(mlx_ptrs, pos, col, AMBIENT);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Brightness");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, ambient.ratio);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Colour");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_colour(mlx_ptrs, pos, col, ambient.colour);
}

void	ft_put_light(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_light light)
{
	pos = ft_put_id(mlx_ptrs, pos, col, light.id);
	pos = ft_put_type(mlx_ptrs, pos, col, LIGHT);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Position");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_3d_point(mlx_ptrs, pos, col, light.pos);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Brightness");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, light.ratio);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Colour");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_colour(mlx_ptrs, pos, col, light.colour);
}
