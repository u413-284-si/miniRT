/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:43:24 by gwolf             #+#    #+#             */
/*   Updated: 2024/07/03 13:21:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_free_mlx(t_mlx_ptrs *mlx_ptrs)
{
	if (mlx_ptrs->mlx_ptr)
	{
		if (mlx_ptrs->img.ptr)
		{
			mlx_destroy_image(mlx_ptrs->mlx_ptr, mlx_ptrs->img.ptr);
			mlx_ptrs->img.addr = NULL;
		}
		if (mlx_ptrs->veil.ptr)
		{
			mlx_destroy_image(mlx_ptrs->mlx_ptr, mlx_ptrs->veil.ptr);
			mlx_ptrs->veil.addr = NULL;
		}
		if (mlx_ptrs->win_ptr)
		{
			mlx_destroy_window(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr);
			mlx_ptrs->win_ptr = NULL;
		}
		mlx_destroy_display(mlx_ptrs->mlx_ptr);
		free(mlx_ptrs->mlx_ptr);
		mlx_ptrs->mlx_ptr = NULL;
	}
}

#ifndef IS_BONUS

void	ft_render_cleanup(t_render *render)
{
	free(render->scene.obj);
	free(render->scene.lsrc);
	ft_free_mlx(&render->mlx_ptrs);
	free(render->cam.pix_cache);
}
#endif
