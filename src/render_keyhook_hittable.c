/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/20 11:56:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_change_active_hittable(int key, t_entities *scene)
{
	if (scene->active == -1)
		return ;
	if (key == K_ONE)
	{
		scene->active--;
		if (scene->active < 0)
			scene->active = scene->total - 1;
	}
	if (key == K_TWO)
	{
		scene->active++;
		if (scene->active == scene->total)
			scene->active = 0;
	}
}

void	ft_manip_hittable(int key, t_entities *scene)
{
	if (scene->obj[scene->active].type == SPHERE)
		ft_manip_sphere(key, &scene->obj[scene->active].params.sp);
	else if (scene->obj[scene->active].type == PLANE)
		ft_manip_plane(key, &scene->obj[scene->active].params.pl);
	else if (scene->obj[scene->active].type == CYLINDER)
		ft_manip_cylinder(key, &scene->obj[scene->active].params.cy);
}


void	ft_manip_sphere(int key, t_sphere *sp)
{
	if (key == K_Q)
		sp->centre.z -= MV_UNIT;
	else if (key == K_E)
		sp->centre.z += MV_UNIT;
	else if (key == K_W)
		sp->centre.y += MV_UNIT;
	else if (key == K_S)
		sp->centre.y -= MV_UNIT;
	else if (key == K_D)
		sp->centre.x += MV_UNIT;
	else if (key == K_A)
		sp->centre.x -= MV_UNIT;
	else if (key == K_R)
		sp->r -= MV_UNIT;
	else if (key == K_F)
		sp->r += MV_UNIT;
	ft_print_sphere(*sp);
}

void	ft_manip_plane(int key, t_plane *pl)
{
	if (key == K_Q)
		pl->point.z -= MV_UNIT;
	else if (key == K_E)
		pl->point.z += MV_UNIT;
	else if (key == K_W)
		pl->point.y += MV_UNIT;
	else if (key == K_S)
		pl->point.y -= MV_UNIT;
	else if (key == K_D)
		pl->point.x += MV_UNIT;
	else if (key == K_A)
		pl->point.x -= MV_UNIT;
	else if (key == K_ARROW_L)
		pl->normal = ft_vec3_rotate_x(pl->normal, MV_UNIT);
	else if (key == K_ARROW_R)
		pl->normal = ft_vec3_rotate_x(pl->normal, -MV_UNIT);
	else if (key == K_ARROW_U)
		pl->normal = ft_vec3_rotate_y(pl->normal, MV_UNIT);
	else if (key == K_ARROW_D)
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
	if (key == K_Q)
	{
		cy->centre.z -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == K_E)
	{
		cy->centre.z += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == K_W)
	{
		cy->centre.y += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == K_S)
	{
		cy->centre.y -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == K_D)
	{
		cy->centre.x += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == K_A)
	{
		cy->centre.x -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == K_ARROW_L)
		cy->axis = ft_vec3_rotate_x(cy->axis, MV_UNIT);
	else if (key == K_ARROW_R)
		cy->axis = ft_vec3_rotate_x(cy->axis, -MV_UNIT);
	else if (key == K_ARROW_U)
		cy->axis = ft_vec3_rotate_y(cy->axis, MV_UNIT);
	else if (key == K_ARROW_D)
		cy->axis = ft_vec3_rotate_y(cy->axis, -MV_UNIT);
	ft_print_cylinder(*cy);
}

