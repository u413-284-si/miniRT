/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/22 21:24:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_change_active_hittable(int key, t_entities *scene)
{
	if (scene->active == -1)
		return ;
	if (key == XK_1)
	{
		scene->active--;
		if (scene->active < 0)
			scene->active = scene->total - 1;
	}
	if (key == XK_2)
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
	if (key == XK_q)
		sp->centre.z -= MV_UNIT;
	else if (key == XK_e)
		sp->centre.z += MV_UNIT;
	else if (key == XK_w)
		sp->centre.y += MV_UNIT;
	else if (key == XK_s)
		sp->centre.y -= MV_UNIT;
	else if (key == XK_d)
		sp->centre.x += MV_UNIT;
	else if (key == XK_a)
		sp->centre.x -= MV_UNIT;
	else if (key == XK_r)
		sp->r -= MV_UNIT;
	else if (key == XK_f)
		sp->r += MV_UNIT;
	ft_print_sphere(*sp);
}

void	ft_manip_plane(int key, t_plane *pl)
{
	if (key == XK_q)
		pl->point.z -= MV_UNIT;
	else if (key == XK_e)
		pl->point.z += MV_UNIT;
	else if (key == XK_w)
		pl->point.y += MV_UNIT;
	else if (key == XK_s)
		pl->point.y -= MV_UNIT;
	else if (key == XK_d)
		pl->point.x += MV_UNIT;
	else if (key == XK_a)
		pl->point.x -= MV_UNIT;
	else if (key == XK_Left)
		pl->normal = ft_vec3_rotate_x(pl->normal, MV_UNIT);
	else if (key == XK_Right)
		pl->normal = ft_vec3_rotate_x(pl->normal, -MV_UNIT);
	else if (key == XK_Up)
		pl->normal = ft_vec3_rotate_y(pl->normal, MV_UNIT);
	else if (key == XK_Down)
		pl->normal = ft_vec3_rotate_y(pl->normal, -MV_UNIT);
	ft_print_plane(*pl);
}

void	ft_cy_calc_caps(t_cylinder *cy)
{
	cy->cap1 = ft_vec3_add(cy->centre, ft_vec3_scale(cy->axis, -cy->h / 2.0));
	cy->cap2 = ft_vec3_add(cy->centre, ft_vec3_scale(cy->axis, cy->h / 2.0));
}

void	ft_manip_cylinder(int key, t_cylinder *cy)
{
	if (key == XK_q)
	{
		cy->centre.z -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == XK_e)
	{
		cy->centre.z += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == XK_w)
	{
		cy->centre.y += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == XK_s)
	{
		cy->centre.y -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == XK_d)
	{
		cy->centre.x += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == XK_a)
	{
		cy->centre.x -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == XK_Left)
		cy->axis = ft_vec3_rotate_x(cy->axis, MV_UNIT);
	else if (key == XK_Right)
		cy->axis = ft_vec3_rotate_x(cy->axis, -MV_UNIT);
	else if (key == XK_Up)
		cy->axis = ft_vec3_rotate_y(cy->axis, MV_UNIT);
	else if (key == XK_Down)
		cy->axis = ft_vec3_rotate_y(cy->axis, -MV_UNIT);
	ft_print_cylinder(*cy);
}

