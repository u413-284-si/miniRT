/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_compose_image_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:22:40 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/07 18:16:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "time_bonus.h"

int	ft_draw_scene(t_render *render)
{
	const uint64_t	starttime = ft_get_timeofday_ms();

	if (render->is_printing)
	{
		mlx_string_put(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
			200, 20, render->menu.font_col, "Printing - Please wait");
		ft_output_as_ppm(render->mlx_ptrs.img, &render->is_printing);
		mlx_do_key_autorepeaton(render->mlx_ptrs.mlx_ptr);
		return (0);
	}
	if (render->is_changed)
	{
		ft_render_image(render);
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		ft_blend_background(&render->mlx_ptrs.img, &render->mlx_ptrs.veil,
			render->menu);
		render->last_render_time = ft_get_timeofday_ms() - starttime;
		printf("MS: %lu\n", render->last_render_time);
		printf("FPS: %lu\n", 1000 / (render->last_render_time));
		render->is_changed = false;
	}
	ft_menu_put_text(render);
	return (0);
}
