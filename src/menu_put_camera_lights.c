/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_camera_lights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:10:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/03 16:09:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_cam cam)
{
	mlx_set_font(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, REGULAR);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Camera");
	pos.y += Y_NEXT_LINE_BIG;
	ft_mlx_put_str(mlx_ptrs, pos, col, "Look from");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_3d_point(mlx_ptrs, pos, col, cam.centre);
	ft_mlx_put_str(mlx_ptrs, pos, col, "Look at");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_unit_vec(mlx_ptrs, pos, col, cam.centre);
	ft_mlx_put_str(mlx_ptrs, pos, col, "FOV");
	pos.y += Y_NEXT_LINE;
	pos = ft_put_float_value(mlx_ptrs, pos, col, cam.hfov);
}

void	ft_put_ambient(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
						t_light ambient)
{
	ft_mlx_put_str(mlx_ptrs, pos, col, "Ambient");
	pos.y += Y_NEXT_LINE_BIG;
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
	ft_mlx_put_str(mlx_ptrs, pos, col, "Light");
	pos.y += Y_NEXT_LINE_BIG;
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
