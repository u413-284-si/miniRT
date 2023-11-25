/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/22 12:38:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_end_loop(t_render *render)
{
	mlx_loop_end(render->mlx_ptr);
	return (0);
}

void	ft_start_mlx_loop(t_render *render, t_image image, t_entities scene, t_cam cam, t_viewport vp);
{
	int pos[2]={10,10};
	mlx_hook(render->win_ptr, KeyPress, KeyPressMask, ft_keyhook_press, render);
	mlx_hook(render->win_ptr, DestroyNotify, StructureNotifyMask, ft_end_loop, render);
	ft_render_image(image, cam, viewport, scene, &render);
	ft_mlx_put_float(render, pos, 34.56, 2);
	pos[1] = 20;
	ft_mlx_put_int(render, pos, 12, 6);
	mlx_loop(render->mlx_ptr);
	(void)image;
	//ft_output_as_ppm((int *)render->buffer.addr, image.image_width, image.image_height);
	ft_free_mlx(render->mlx_ptr, render->win_ptr, render->buffer.ptr);
}
