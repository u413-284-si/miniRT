/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:13 by u413q             #+#    #+#             */
/*   Updated: 2023/11/07 12:44:44 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	ft_create_scene(t_entities *scene)
{
	//int	i;

	scene->lsrc_count = 1;
	scene->sp_count = 0;
	scene->pl_count = 1;
	scene->cy_count = 0;
	scene->total = scene->sp_count + scene->pl_count + scene->cy_count;
	scene->obj = malloc(scene->total * sizeof(t_hittable));
	if (!scene->obj)
		exit(232);
	scene->lsrc = malloc(scene->lsrc_count * sizeof(t_light));
	if (!scene->lsrc)
		exit(232);
	//i = -1;
	//while (++i < scene->sp_count)
	ft_initiate_lights(scene);
	//ft_initiate_spheres(scene->obj);
	ft_initiate_planes(scene->obj);
}

void	ft_initiate_lights(t_entities *scene)
{
	scene->ambient.colour.r = 1.0;
	scene->ambient.colour.g = 1.0;
	scene->ambient.colour.b = 1.0;
	scene->ambient.ratio = 0.2;
	scene->lsrc[0].colour.r = 1.0;
	scene->lsrc[0].colour.g = 1.0;
	scene->lsrc[0].colour.b = 1.0;
	scene->lsrc[0].ratio = 0.7;
	scene->lsrc[0].pos.x = -40.0;
	scene->lsrc[0].pos.y = 50.0;
	scene->lsrc[0].pos.z = 0.0;
}

void	ft_initiate_spheres(t_hittable *obj)
{
	obj[0].id = 0;
	obj[0].type = SPHERE;
	obj[0].params.sp.centre.x = 0.0;
	obj[0].params.sp.centre.y = 0.0;
	obj[0].params.sp.centre.z = -1.0;
	obj[0].params.sp.r = 0.5;
	obj[0].params.sp.colour.r = 1.0;
	obj[0].params.sp.colour.g = 0.0;
	obj[0].params.sp.colour.b = 0.0;
	obj[1].id = 1;
	obj[1].type = SPHERE;
	obj[1].params.sp.centre.x = 0.0;
	obj[1].params.sp.centre.y = -100.5;
	obj[1].params.sp.centre.z = -1.0;
	obj[1].params.sp.r = 100;
	obj[1].params.sp.colour.r = 0.0;
	obj[1].params.sp.colour.g = 1.0;
	obj[1].params.sp.colour.b = 0.0;
}

void	ft_initiate_planes(t_hittable *obj)
{
	obj[0].id = 0;
	obj[0].type = PLANE;
	obj[0].params.pl.point.x = 0.0;
	obj[0].params.pl.point.y = 0.0;
	obj[0].params.pl.point.z = -1.0;
	obj[0].params.pl.normal.x = 0.707;
	obj[0].params.pl.normal.y = 0.0;
	obj[0].params.pl.normal.z = 0.707;
	obj[0].params.pl.colour.r = 0.0;
	obj[0].params.pl.colour.b = 0.7;
	obj[0].params.pl.colour.g = 0.9412;
}
