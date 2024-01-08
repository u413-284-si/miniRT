/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_press.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 12:17:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	ft_is_option_key(int key)
{
	return (key == XK_Escape || key == XK_Shift_L || key == XK_Control_L
		|| key == XK_i);
}

static bool	ft_is_manip_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d
		|| key == XK_q || key == XK_e || key == XK_r || key == XK_f
		|| key == XK_t || key == XK_g || key == XK_n || key == XK_m
		|| (key >= XK_Left && key <= XK_Down)
		|| (key >= XK_0 && key <= XK_9));
}



int	ft_keyhook_press(int key, t_render *render)
{
	if (ft_is_option_key(key))
		ft_change_options(key, render);
	else if (ft_is_manip_key(key))
	{
		if (render->mode == CTRL_SCENE)
			ft_manip_scene(key, &render->scene, &render->active_hittable);
		else if (render->mode == CTRL_CAM)
			ft_manip_cam(key, &render->cam);
		else if (render->mode == CTRL_LIGHT)
			ft_manip_light(key, &render->scene, &render->active_light);
		render->is_changed = true;
	}
	return (0);
}
