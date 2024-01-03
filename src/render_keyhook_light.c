/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:40:21 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/03 16:18:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_manip_light_src(int key, t_light *light)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &light->colour);
	else if (key == XK_r)
		light->ratio -= MV_UNIT;
	else if (key == XK_f)
		light->ratio += MV_UNIT;
	else
		ft_keyhook_mv_point(key, &light->pos);
}

void	ft_manip_ambient(int key, t_light *ambient)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &ambient->colour);
	else if (key == XK_r)
		ambient->ratio -= MV_UNIT;
	else if (key == XK_f)
		ambient->ratio += MV_UNIT;
}

void	ft_change_active_light(int key, t_entities *scene, int *active)
{
	if (*active == -1)
		return ;
	if (key == XK_n)
	{
		*active -= 1;
		if (*active < 0)
			*active = scene->lsrc_count + 1 - 1;
	}
	if (key == XK_m)
	{
		*active += 1;
		if (*active == scene->lsrc_count + 1)
			*active = 0;
	}
}

void	ft_manip_light(int key, t_entities *scene, int *active)
{
	if (key == XK_n || key == XK_m)
		return (ft_change_active_light(key, scene, active));
	if (*active == 0)
		ft_manip_ambient(key, &scene->ambient);
	else
		ft_manip_light_src(key, &scene->lsrc[*active - 1]);
}
