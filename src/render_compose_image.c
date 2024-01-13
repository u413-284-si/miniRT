/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_compose_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:21:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/12 19:04:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_draw_scene(t_render *render)
{
	if (render->is_printing)
	{
		mlx_string_put(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
			200, 20, render->menu.font_col, "Printing - Please wait");
		ft_output_as_ppm(render->mlx_ptrs.img, &render->is_printing);
		mlx_do_key_autorepeaton(render->mlx_ptrs.mlx_ptr);
		return (0);
	}
	if (ft_option_isset(render->options, O_SCENE_CHANGED))
	{
		ft_render_image(render);
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		ft_blend_background(&render->mlx_ptrs.img, &render->mlx_ptrs.veil,
			render->menu);
		ft_option_clear(&render->options, O_SCENE_CHANGED);
	}
	ft_menu_put_text(render);
	return (0);
}
