/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:43:24 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/17 16:51:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_free_mlx(t_mlx_ptrs *mlx_ptrs)
{
	if (mlx_ptrs->mlx_ptr)
	{
		if (mlx_ptrs->img.ptr)
			mlx_destroy_image(mlx_ptrs->mlx_ptr, mlx_ptrs->img.ptr);
		if (mlx_ptrs->veil.ptr)
			mlx_destroy_image(mlx_ptrs->mlx_ptr, mlx_ptrs->veil.ptr);
		if (mlx_ptrs->win_ptr)
			mlx_destroy_window(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr);
		mlx_destroy_display(mlx_ptrs->mlx_ptr);
		free(mlx_ptrs->mlx_ptr);
	}
}

void	ft_free_scene(t_entities *scene)
{
	free(scene->obj);
	free(scene->lsrc);
}

static void	ft_free_cam(t_cam *cam)
{
	free(cam->ray_cache);
}

void	ft_render_cleanup(t_render *render)
{
	ft_free_scene(&render->scene);
	ft_free_mlx(&render->mlx_ptrs);
	ft_free_cam(&render->cam);
}
