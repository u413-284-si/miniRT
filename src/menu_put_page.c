/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:16:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 15:35:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_page_scene(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_hittable active, t_pages cur_page)
{
	if (cur_page == PAGE_SCENE)
		ft_put_hittable(mlx_ptrs, put, active);
	else
		ft_put_ctrl_hittable(mlx_ptrs, put, active);
}

void	ft_put_page_ambient(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_light ambient, t_pages cur_page)
{
	if (cur_page == PAGE_LIGHT)
		ft_put_ambient(mlx_ptrs, put, ambient);
	else
		ft_put_ctrl_light(mlx_ptrs, put, 0);
}

void	ft_put_page_light(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_light light, t_pages cur_page)
{
	if (cur_page == PAGE_LIGHT)
		ft_put_light(mlx_ptrs, put, light);
	else
		ft_put_ctrl_light(mlx_ptrs, put, light.id);
}

void	ft_put_page_cam(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_cam cam, t_pages cur_page)
{
	if (cur_page == PAGE_CAM)
		ft_put_camera(mlx_ptrs, put, cam);
	else
		ft_put_ctrl_cam(mlx_ptrs, put);
}
