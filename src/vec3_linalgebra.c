/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_linalgebra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:52:25 by u413q             #+#    #+#             */
/*   Updated: 2023/10/26 15:24:15 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

float	ft_vec3_abs(t_vec3 v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vec3	ft_vec3_norm(t_vec3 v)
{
	return (ft_vec3_scale(v, 1.0 / ft_vec3_abs(v)));
}

float	ft_vec3_angle(t_vec3 v1, t_vec3 v2)
{
	float	dot_product;

	dot_product = ft_vec3_dot(v1, v2);
	return (acos(dot_product / (ft_vec3_abs(v1) * ft_vec3_abs(v2))));
}
