/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_arithmetics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:56:24 by u413q             #+#    #+#             */
/*   Updated: 2023/10/26 14:52:36 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	rtrn;

	rtrn.x = v1.x + v2.x;
	rtrn.y = v1.y + v2.y;
	rtrn.z = v1.z + v2.z;
	return (rtrn);
}

t_vec3	ft_vec3_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	rtrn;

	rtrn.x = v1.x - v2.x;
	rtrn.y = v1.y - v2.y;
	rtrn.z = v1.z - v2.z;
	return (rtrn);
}

t_vec3	ft_vec3_scale(t_vec3 v, float a)
{
	t_vec3	rtrn;

	rtrn.x = v.x * a;
	rtrn.y = v.y * a;
	rtrn.z = v.z * a;
	return (rtrn);
}

float	ft_vec3_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	ft_vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	rtrn;

	rtrn.x = v1.y * v2.z - v1.z * v2.y;
	rtrn.y = v1.z * v2.x - v1.x * v2.z;
	rtrn.z = v1.x * v2.y - v1.y * v2.x;
	return (rtrn);
}
