/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:42:02 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 12:14:36 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#ifndef IS_BONUS

t_err	ft_render_init(t_render *render)
{
	if (ft_init_mlx_ptrs(&render->mlx_ptrs, &render->win_size))
		return (ERROR);
	if (ft_cam_init(&render->cam, render->mlx_ptrs.img.size))
		return (ERROR);
	ft_menu_init(&render->menu, MENU_OPACITY, MENU_BACK, MENU_FONT);
	if (render->scene.total == 0)
		render->active_hittable = -1;
	ft_option_set(&render->options, O_MODE_SCENE);
	ft_option_set(&render->options, O_SCENE_CHANGED);
	ft_option_set(&render->options, O_MANIP_LOW);
	return (SUCCESS);
}
#endif

void	ft_menu_init(t_menu *menu, uint8_t alpha, uint32_t colour,
			uint32_t font_col)
{
	menu->inv_alpha = 255 - alpha;
	menu->rb = (colour & 0xFF00FF) * alpha;
	menu->g = (colour & 0x00FF00) * alpha;
	menu->font_col = font_col;
}
