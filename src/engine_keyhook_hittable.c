/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook_hittable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:50:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/18 18:00:44 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_change_active_hittable(int key, t_entities *scene)
{
	if (scene->active == -1)
		return ;
	if (key == KEY_ONE)
	{
		scene->active--;
		if (scene->active < 0)
			scene->active = scene->total - 1;
	}
	if (key == KEY_TWO)
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
		sp->centre.x += MV_UNIT;
	else if (key == KEY_A)
		sp->centre.x -= MV_UNIT;
	else if (key == KEY_R)
		sp->r -= MV_UNIT;
	else if (key == KEY_F)
		sp->r += MV_UNIT;
	ft_print_sphere(*sp);
}

void	ft_manip_plane(int key, t_plane *pl)
{
	if (key == KEY_Q)
		pl->point.z -= MV_UNIT;
	else if (key == KEY_E)
		pl->point.z += MV_UNIT;
	else if (key == KEY_W)
		pl->point.y += MV_UNIT;
	else if (key == KEY_S)
		pl->point.y -= MV_UNIT;
	else if (key == KEY_D)
		pl->point.x += MV_UNIT;
	else if (key == KEY_A)
		pl->point.x -= MV_UNIT;
	else if (key == KEY_ARROW_LEFT)
		pl->normal = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_x(MV_UNIT), pl->normal));
	else if (key == KEY_ARROW_RIGHT)
		pl->normal = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_x(-MV_UNIT), pl->normal));
	else if (key == KEY_ARROW_UP)
		pl->normal = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_y(MV_UNIT), pl->normal));
	else if (key == KEY_ARROW_DOWN)
		pl->normal = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_y(-MV_UNIT), pl->normal));
	ft_print_plane(*pl);
}

void	ft_cy_calc_caps(t_cylinder *cy)
{
	cy->cap1 = ft_vec3_add(cy->centre, ft_vec3_scale(cy->axis, -cy->h / 2.0));
	cy->cap2 = ft_vec3_add(cy->centre, ft_vec3_scale(cy->axis, cy->h / 2.0));
}

void	ft_manip_cylinder(int key, t_cylinder *cy)
{
	if (key == KEY_Q)
	{
		cy->centre.z -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == KEY_E)
	{
		cy->centre.z += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == KEY_W)
	{
		cy->centre.y += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == KEY_S)
	{
		cy->centre.y -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == KEY_D)
	{
		cy->centre.x += MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == KEY_A)
	{
		cy->centre.x -= MV_UNIT;
		ft_cy_calc_caps(cy);
	}
	else if (key == KEY_ARROW_LEFT)
		cy->axis = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_x(MV_UNIT), cy->axis));
	else if (key == KEY_ARROW_RIGHT)
		cy->axis = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_x(-MV_UNIT), cy->axis));
	else if (key == KEY_ARROW_UP)
		cy->axis = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_y(MV_UNIT), cy->axis));
	else if (key == KEY_ARROW_DOWN)
		cy->axis = ft_vec3_norm(ft_mat4_mult_vec3(ft_mat4_create_rotate_y(-MV_UNIT), cy->axis));
	ft_print_cylinder(*cy);
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
