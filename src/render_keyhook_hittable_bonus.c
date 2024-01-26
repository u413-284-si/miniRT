/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 18:02:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ft_manip_hittable(int key, t_hittable *hittable, float inc)
{
	if (hittable->type == SPHERE)
		ft_manip_sphere(key, &hittable->params.sp, inc);
	else if (hittable->type == PLANE)
		ft_manip_plane(key, &hittable->params.pl, inc);
	else if (hittable->type == CYLINDER)
		ft_manip_cylinder(key, &hittable->params.cy, inc);
	else if (hittable->type == CONE)
		ft_manip_cone(key, &hittable->params.co, inc);
}

void	ft_manip_cone(int key, t_cone *co, float inc)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &co->colour, inc);
	else if (key >= XK_Left && key <= XK_Down)
		ft_keyhook_rot_vec(key, &co->axis, inc);
	else if (key == XK_r || key == XK_f)
		ft_keyhook_inc_dec(key, &co->r, FLOAT_MAX, inc);
	else if (key == XK_t || key == XK_g)
		ft_keyhook_inc_dec(key, &co->h, FLOAT_MAX, inc);
	else
		ft_keyhook_mv_point(key, &co->apex, inc);
	co->angle = atan(co->r / co->h) + EPSILON;
	co->base = ft_vec3_add(co->apex, ft_vec3_scale(co->axis, co->h));
}
