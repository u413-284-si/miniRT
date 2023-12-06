/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/06 18:57:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_end_loop(void *mlx_ptr)
{
	mlx_loop_end(mlx_ptr);
	return (0);
}

void	ft_start_engine(t_engine *engine)
{
	t_render	*render;

	render = &engine->render;

	mlx_hook(render->win_ptr, KeyPress, KeyPressMask, ft_keyhook_press, render);
	mlx_hook(render->win_ptr, DestroyNotify, StructureNotifyMask, ft_end_loop, render->mlx_ptr);
	mlx_loop_hook(render->mlx_ptr, ft_draw_scene, engine);
	mlx_hook(render->win_ptr, ButtonPress, ButtonPressMask, \
			ft_mouse_hook_press, engine);
	mlx_hook(render->win_ptr, ButtonRelease, ButtonReleaseMask, \
			ft_mouse_hook_release, engine);
	mlx_hook(render->win_ptr, MotionNotify, ButtonMotionMask, \
			ft_mouse_hook_move, engine);
	mlx_loop(render->mlx_ptr);
	ft_free_mlx(render->mlx_ptr, render->win_ptr, render->buffer.ptr);
}
