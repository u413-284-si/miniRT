/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:13 by u413q             #+#    #+#             */
/*   Updated: 2023/10/29 14:00:24 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	ft_create_scene(t_entities *scene)
{
	scene->sp_count = 2;
	scene->sp = malloc(scene->sp_count * sizeof(t_sphere));
	if (!scene->sp)
		exit(232);
	scene->sp[0].centre.x = 0.0;
	scene->sp[0].centre.y = 0.0;
	scene->sp[0].centre.z = -1.0;
	scene->sp[0].r = 0.5;
	scene->sp[1].centre.x = 0.0;
	scene->sp[1].centre.y = -100.5;
	scene->sp[1].centre.z = -1.0;
	scene->sp[1].r = 100;
}
