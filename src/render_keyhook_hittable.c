/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/23 22:16:31 by gwolf            ###   ########.fr       */
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
}

void	ft_manip_hittable(int key, t_hittable *hittable)
{
	if (hittable->type == SPHERE)
		ft_manip_sphere(key, &hittable->params.sp);
	else if (hittable->type == PLANE)
		ft_manip_plane(key, &hittable->params.pl);
	else if (hittable->type == CYLINDER)
		ft_manip_cylinder(key, &hittable->params.cy);
}


void	ft_manip_sphere(int key, t_sphere *sp)
{
	if (key >= XK_1 && key <= XK_6)
		ft_keyhook_change_col(key, &sp->colour);
	else if (key == XK_r)
		sp->r -= MV_UNIT;
	else if (key == XK_f)
		sp->r += MV_UNIT;
	else
		ft_keyhook_mv_point(key, &sp->centre);
	ft_print_sphere(*sp);
}

void	ft_manip_plane(int key, t_plane *pl)
{
	if (key >= XK_Left)
		ft_keyhook_rot_vec(key, &pl->normal);
	else
		ft_keyhook_mv_point(key, &pl->point);
	ft_print_plane(*pl);
}

void	ft_manip_cylinder(int key, t_cylinder *cy)
{
	if (key >= XK_Left)
		ft_keyhook_rot_vec(key, &cy->axis);
	else
	{
		ft_keyhook_mv_point(key, &cy->centre);
		ft_cy_calc_caps(cy);
	}
	ft_print_cylinder(*cy);
}
