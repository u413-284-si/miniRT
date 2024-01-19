/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_compose_image_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:22:40 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 18:42:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

int	ft_draw_scene(t_render *render)
{
	const uint64_t	starttime = ft_get_time_ms();

	if (ft_option_isset(render->options, O_SCENE_CHANGED))
	{
		if (ft_option_isset(render->options, O_IS_THREADED))
		{
			if (ft_spin_threads(render, ft_render_image_threaded)
				|| ft_spin_threads(render, ft_blend_background_threaded))
			{
				ft_option_clear(&render->options, O_IS_THREADED);
				ft_option_set(&render->options, O_SCENE_CHANGED);
				return (1);
			}
		}
		else
		{
			ft_render_image(render);
			ft_blend_background(render);
		}
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		render->last_render_time = ft_get_time_ms() - starttime;
		ft_option_clear(&render->options, O_SCENE_CHANGED);
	}
	ft_menu_put_text(render);
	return (0);
}
