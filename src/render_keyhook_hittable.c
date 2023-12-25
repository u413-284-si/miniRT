/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 19:03:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_change_active_hittable(int key, t_entities *scene)
{
	if (scene->active == -1)
		return ;
	if (key == XK_n)
	{
		scene->active--;
		if (scene->active < 0)
			scene->active = scene->total - 1;
	}
	if (key == XK_m)
	{
		scene->active++;
		if (scene->active == scene->total)
			scene->active = 0;
	}
	ft_print_hittable(scene->obj[scene->active]);
}

void	ft_manip_hittable(int key, t_hittable *hittable)
{
	if (hittable->type == SPHERE)
		ft_manip_sphere(key, &hittable->params.sp);
	else if (hittable->type == PLANE)
		ft_manip_plane(key, &hittable->params.pl);
	else if (hittable->type == CYLINDER)
		ft_manip_cylinder(key, &hittable->params.cy);
	ft_print_hittable(*hittable);
}


void	ft_manip_sphere(int key, t_sphere *sp)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &sp->colour);
	else if (key == XK_r)
		sp->r -= MV_UNIT;
	else if (key == XK_f)
		sp->r += MV_UNIT;
	else
		ft_keyhook_mv_point(key, &sp->centre);
}

void	ft_manip_plane(int key, t_plane *pl)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &pl->colour);
	else if (key >= XK_Left && key <= XK_Down)
		ft_keyhook_rot_vec(key, &pl->normal);
	else
		ft_keyhook_mv_point(key, &pl->point);
}

void	ft_manip_cylinder(int key, t_cylinder *cy)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &cy->colour);
	else if (key >= XK_Left && key <= XK_Down)
		ft_keyhook_rot_vec(key, &cy->axis);
	else if (key == XK_r)
		cy->d -= MV_UNIT;
	else if (key == XK_f)
		cy->d += MV_UNIT;
	else if (key == XK_t)
		cy->h -= MV_UNIT;
	else if (key == XK_g)
		cy->h += MV_UNIT;
	else
	{
		ft_keyhook_mv_point(key, &cy->centre);
		ft_cy_calc_caps(cy);
	}
}
