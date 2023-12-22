/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:13 by u413q             #+#    #+#             */
/*   Updated: 2023/12/22 11:36:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_bonus.h"

void	ft_create_scene(t_entities *scene)
{
	//int	i;

	scene->lsrc_count = 1;
	scene->sp_count = 0;
	scene->pl_count = 0;
	scene->cy_count = 1;
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
	//ft_initiate_planes(scene->obj);
	ft_initiate_cylinders(scene->obj);
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
	scene->lsrc[0].pos.x = 0.0;
	scene->lsrc[0].pos.y = 0.0;
	scene->lsrc[0].pos.z = 0.0;
}

void	ft_initiate_spheres(t_hittable *obj)
{
	obj[0].id = 0;
	obj[0].type = SPHERE;
	obj[0].shininess = 32;
	obj[0].params.sp.centre.x = -cos(M_PI / 4);
	obj[0].params.sp.centre.y = 0.0;
	obj[0].params.sp.centre.z = -1.0;
	obj[0].params.sp.r = cos(M_PI / 4);
	obj[0].params.sp.colour.r = 0.0;
	obj[0].params.sp.colour.g = 0.0;
	obj[0].params.sp.colour.b = 1.0;
	obj[1].id = 1;
	obj[1].type = SPHERE;
	obj[1].shininess = 64;
	obj[1].params.sp.centre.x = cos(M_PI / 4);
	obj[1].params.sp.centre.y = 0;
	obj[1].params.sp.centre.z = -1.0;
	obj[1].params.sp.r = cos(M_PI / 4);
	obj[1].params.sp.colour.r = 1.0;
	obj[1].params.sp.colour.g = 0.0;
	obj[1].params.sp.colour.b = 0.0;
}

void	ft_initiate_planes(t_hittable *obj)
{
	obj[0].id = 0;
	obj[0].type = PLANE;
	obj[0].params.pl.point.x = 1.0;
	obj[0].params.pl.point.y = 0.0;
	obj[0].params.pl.point.z = 0.0;
	obj[0].params.pl.normal.x = 0.707;
	obj[0].params.pl.normal.y = 0.0;
	obj[0].params.pl.normal.z = 0.0;
	obj[0].params.pl.colour.r = 0.0;
	obj[0].params.pl.colour.b = 0.7;
	obj[0].params.pl.colour.g = 0.9412;
}

void	ft_initiate_cylinders(t_hittable *obj)
{
	obj[0].id = 0;
	obj[0].type = CYLINDER;
	obj[0].shininess = 32;
	obj[0].params.cy.centre.x = 0.0;
	obj[0].params.cy.centre.y = 0.0;
	obj[0].params.cy.centre.z = 50.0;
	obj[0].params.cy.axis.x = 1.0;
	obj[0].params.cy.axis.y = 1.0;
	obj[0].params.cy.axis.z = 1.0;
	obj[0].params.cy.d = 16;
	obj[0].params.cy.h = 20;
	obj[0].params.cy.cap1 = ft_vec3_add(obj[0].params.cy.centre, \
		ft_vec3_scale(obj[0].params.cy.axis, -obj[0].params.cy.h / 2.0));
	obj[0].params.cy.cap2 = ft_vec3_add(obj[0].params.cy.centre, \
		ft_vec3_scale(obj[0].params.cy.axis, obj[0].params.cy.h / 2.0));
	obj[0].params.cy.colour.r = 1.0;
	obj[0].params.cy.colour.g = 0.0;
	obj[0].params.cy.colour.b = 0.0;
}
