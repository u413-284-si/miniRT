/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/21 18:49:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_end_loop(t_render *render)
{
	mlx_loop_end(render->mlx_ptr);
	return (0);
}

void	ft_start_mlx_loop(t_render *render, t_image image)
{
	mlx_hook(render->win_ptr, KeyPress, KeyPressMask, ft_keyhook_press, render);
	mlx_hook(render->win_ptr, DestroyNotify, StructureNotifyMask, ft_end_loop, render);
	mlx_loop(render->mlx_ptr);
	ft_print_image_as_ppm((int *)render->buffer.addr, image.image_width, image.image_height);
	ft_free_mlx(render->mlx_ptr, render->win_ptr, render->buffer.ptr);
}
