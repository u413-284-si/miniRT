/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_select.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:14:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/21 23:22:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_change_active(int key, int total, int *active)
{
	if (*active == -1)
		return ;
	if (key == XK_n)
	{
		*active -= 1;
		if (*active < 0)
			*active = total - 1;
	}
	if (key == XK_m)
	{
		*active += 1;
		if (*active >= total)
			*active = 0;
	}
}

void	ft_change_select(int key, t_render *render)
{
	if (ft_option_isset(render->options, O_MODE_CAM))
		return ;
	else if (ft_option_isset(render->options, O_MODE_SCENE))
		ft_change_active(key, render->scene.total, &render->active_hittable);
	else if (ft_option_isset(render->options, O_MODE_LIGHT))
		ft_change_active(key, render->scene.lsrc_count + 1,
			&render->active_light);
}
