/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 15:24:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_manip_hittable(int key, t_hittable *hittable, float inc)
{
	if (hittable->type == SPHERE)
		ft_manip_sphere(key, &hittable->params.sp, inc);
	else if (hittable->type == PLANE)
		ft_manip_plane(key, &hittable->params.pl, inc);
	else if (hittable->type == CYLINDER)
		ft_manip_cylinder(key, &hittable->params.cy, inc);
}

void	ft_manip_sphere(int key, t_sphere *sp, float inc)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &sp->colour, inc);
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &sp->r, FLOAT_MAX, inc);
	else
		ft_keyhook_mv_point(key, &sp->centre, inc);
}

void	ft_manip_plane(int key, t_plane *pl, float inc)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &pl->colour, inc);
	else if (key >= XK_Left && key <= XK_Down)
		ft_keyhook_rot_vec(key, &pl->normal, inc);
	else
		ft_keyhook_mv_point(key, &pl->point, inc);
}

void	ft_manip_cylinder(int key, t_cylinder *cy, float inc)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &cy->colour, inc);
	else if (key >= XK_Left && key <= XK_Down)
		ft_keyhook_rot_vec(key, &cy->axis, inc);
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &cy->r, FLOAT_MAX, inc);
	else if (key == XK_t || key == XK_g)
		ft_keyhook_inc_dec(key, &cy->h, FLOAT_MAX, inc);
	else
	{
		ft_keyhook_mv_point(key, &cy->centre, inc);
		ft_cy_calc_caps(cy);
	}
}
