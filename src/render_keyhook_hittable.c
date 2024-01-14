/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 19:42:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &sp->colour);
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &sp->d, FLOAT_MAX);
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
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &cy->d, FLOAT_MAX);
	else if (key == XK_t || key == XK_g)
		ft_keyhook_inc_dec(key, &cy->h, FLOAT_MAX);
	else
	{
		ft_keyhook_mv_point(key, &cy->centre);
		ft_cy_calc_caps(cy);
	}
}
