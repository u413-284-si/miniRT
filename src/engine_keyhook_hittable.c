/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 11:50:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_change_active_hittable(int key, t_entities *scene)
{
	if (scene->active == -1)
		return ;
	if (key == KEY_ARROW_LEFT)
	{
		scene->active--;
		if (scene->active < 0)
			scene->active = scene->total - 1;
	}
	if (key == KEY_ARROW_RIGHT)
	{
		scene->active++;
		if (scene->active == scene->total)
			scene->active = 0;
	}
}

void	ft_manip_sphere(int key, t_sphere *sp)
{
	if (key == KEY_Q)
		sp->centre.z -= MV_UNIT;
	else if (key == KEY_E)
		sp->centre.z += MV_UNIT;
	else if (key == KEY_W)
		sp->centre.y += MV_UNIT;
	else if (key == KEY_S)
		sp->centre.y -= MV_UNIT;
	else if (key == KEY_D)
		sp->centre.x -= MV_UNIT;
	else if (key == KEY_A)
		sp->centre.x += MV_UNIT;
	else if (key == KEY_R)
		sp->r -= MV_UNIT;
	else if (key == KEY_F)
		sp->r += MV_UNIT;
}

void	ft_manip_hittable(int key, t_entities *scene)
{
	if (scene->obj[scene->active].type == SPHERE)
		ft_manip_sphere(key, &scene->obj[scene->active].params.sp);
}
