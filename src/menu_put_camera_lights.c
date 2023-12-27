/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_camera_lights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:10:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 17:14:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_cam cam)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Camera");
	pos.y += 20;
	ft_put_3d_point(mlx_ptrs, pos, cam.look_from, "Look from");
	pos.y += 80;
	ft_put_unit_vec(mlx_ptrs, pos, cam.look_at, "Look at");
	pos.y += 80;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "FOV");
	pos.y += 20;
	ft_mlx_put_float(mlx_ptrs, pos, (t_numinfo){.numf = cam.hfov, .pad = 3, .prec = 2});
}

void	ft_put_light(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_light light)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Light");
	pos.y += 20;
	ft_put_3d_point(mlx_ptrs, pos, light.pos, "Position");
	pos.y += 80;
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, pos.x, pos.y, 0x0, "Brightness");
	pos.y += 20;
	ft_mlx_put_float(mlx_ptrs, pos, (t_numinfo){.numf = light.ratio, .pad = 3, .prec = 2});
	pos.y += 20;
	ft_put_colour(mlx_ptrs, pos, light.colour);
}
