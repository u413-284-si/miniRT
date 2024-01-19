/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:40:21 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/09 17:11:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_manip_light_src(int key, t_light *light, float inc)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &light->colour, inc);
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &light->ratio, 1.0, inc * 0.1);
	else
		ft_keyhook_mv_point(key, &light->pos, inc);
}

void	ft_manip_ambient(int key, t_light *ambient, float inc)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &ambient->colour, inc);
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &ambient->ratio, 1.0, inc * 0.1);
}

void	ft_change_active_light(int key, t_entities *scene, int *active)
{
	if (*active == -1)
		return ;
	if (key == XK_n)
	{
		*active -= 1;
		if (*active < 0)
			*active = scene->lsrc_count;
	}
	if (key == XK_m)
	{
		*active += 1;
		if (*active > scene->lsrc_count)
			*active = 0;
	}
}

void	ft_manip_light(int key, t_entities *scene, int *active, float inc)
{
	if (key == XK_n || key == XK_m)
		return (ft_change_active_light(key, scene, active));
	if (*active == 0)
		ft_manip_ambient(key, &scene->ambient, inc);
	else
		ft_manip_light_src(key, &scene->lsrc[*active - 1], inc);
}
