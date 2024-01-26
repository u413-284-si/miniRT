/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:42:02 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/25 00:56:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_err	ft_render_init(t_render *render)
{
	if (ft_init_mlx_ptrs(&render->mlx_ptrs, false))
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
