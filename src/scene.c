/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:13 by u413q             #+#    #+#             */
/*   Updated: 2023/11/01 14:37:07 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	ft_create_scene(t_entities *scene)
{
	scene->sp_count = 2;
	scene->lsrc_count = 1;
	scene->sp = malloc(scene->sp_count * sizeof(t_sphere));
	if (!scene->sp)
		exit(232);
	scene->lsrc = malloc(scene->lsrc_count * sizeof(t_light));
	if (!scene->lsrc)
		exit(232);
	scene->sp[0].centre.x = 0.0;
	scene->sp[0].centre.y = 0.0;
	scene->sp[0].centre.z = -1.0;
	scene->sp[0].r = 0.5;
	scene->sp[0].colour.r = 1.0;
	scene->sp[0].colour.g = 0.0;
	scene->sp[0].colour.b = 0.0;
	scene->sp[1].centre.x = 0.0;
	scene->sp[1].centre.y = -100.5;
	scene->sp[1].centre.z = -1.0;
	scene->sp[1].r = 100;
	scene->sp[1].colour.r = 0.0;
	scene->sp[1].colour.g = 1.0;
	scene->sp[1].colour.b = 0.0;
	scene->ambient.colour.r = 1.0;
	scene->ambient.colour.g = 1.0;
	scene->ambient.colour.b = 1.0;
	scene->ambient.ratio = 1.0;
	scene->lsrc[0].colour.r = 1.0;
	scene->lsrc[0].colour.g = 1.0;
	scene->lsrc[0].colour.b = 1.0;
	scene->lsrc[0].ratio = 0.6;
	scene->lsrc[0].pos.x = -40.0;
	scene->lsrc[0].pos.y = 50.0;
	scene->lsrc[0].pos.z = 0.0;
}
