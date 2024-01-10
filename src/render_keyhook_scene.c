/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:05:26 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/09 16:41:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_manip_scene(int key, t_entities *scene, int *active, float inc)
{
	if (key == XK_n || key == XK_m)
		ft_change_active_hittable(key, scene, active);
	else
		ft_manip_hittable(key, &scene->obj[*active], inc);
}

void	ft_change_active_hittable(int key, t_entities *scene, int *active)
{
	if (*active == -1)
		return ;
	if (key == XK_n)
	{
		*active -= 1;
		if (*active < 0)
			*active = scene->total - 1;
	}
	if (key == XK_m)
	{
		*active += 1;
		if (*active == scene->total)
			*active = 0;
	}
}
