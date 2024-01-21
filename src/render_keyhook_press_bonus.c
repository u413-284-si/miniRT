/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_press_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/21 12:57:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

static bool	ft_is_bonus_key(int key)
{
	return (key == XK_o || key == XK_p || key == XK_j || key == XK_k);
}

static bool	ft_is_option_key(int key)
{
	return (key == XK_Escape || key == XK_Shift_L || key == XK_Control_L
		|| key == XK_i || key == XK_u);
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
	float	inc;

	if (ft_is_printing(render))
		return (0);
	if (ft_is_option_key(key))
		ft_change_options(key, render);
	else if (ft_is_bonus_key(key))
		ft_change_options_bonus(key, render);
	else if (ft_is_manip_key(key))
	{
		inc = ft_get_increment(render->options);
		if (ft_option_isset(render->options, O_MODE_SCENE))
			ft_manip_scene(key, &render->scene, &render->active_hittable, inc);
		else if (ft_option_isset(render->options, O_MODE_LIGHT))
			ft_manip_light(key, &render->scene, &render->active_light, inc);
		else if (ft_option_isset(render->options, O_MODE_CAM))
			ft_manip_cam(key, &render->cam, inc, &render->options);
		ft_option_set(&render->options, O_SCENE_CHANGED);
	}
	return (0);
}
