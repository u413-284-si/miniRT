/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:13 by u413q             #+#    #+#             */
/*   Updated: 2023/10/28 17:41:17 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool	ft_hit_sphere(t_vec3 sp_centre, float r, t_ray ray)
{
	t_vec3	sp_centre_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	sp_centre_ray = ft_vec3_sub(ray.origin, sp_centre);
	a = ft_vec3_dot(ray.direction, ray.direction);
	b = 2.0 * ft_vec3_dot(ray.direction, sp_centre_ray);
	c = ft_vec3_dot(sp_centre_ray, sp_centre_ray) - pow(r, 2);
	discriminant = pow(b, 2) - 4.0 * a * c;
	if (discriminant >= 0)
		return (true);
	else
		return (false);
}
