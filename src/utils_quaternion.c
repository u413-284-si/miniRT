/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quaternion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:14:06 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/22 18:36:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_quaternion	ft_quaternion_mult(t_quaternion q1, t_quaternion q2)
{
	return ((t_quaternion){
		.scalar = q1.scalar * q2.scalar
		- q1.vector.x * q2.vector.x
		- q1.vector.y * q2.vector.y
		- q1.vector.z * q2.vector.z,
		.vector.x = q1.scalar * q2.vector.x
		+ q1.vector.x * q2.scalar
		+ q1.vector.y * q2.vector.z
		- q1.vector.z * q2.vector.y,
		.vector.y = q1.scalar * q2.vector.y
		- q1.vector.x * q2.vector.z
		+ q1.vector.y * q2.scalar
		+ q1.vector.z * q2.vector.x,
		.vector.z = q1.scalar * q2.vector.z
		+ q1.vector.x * q2.vector.y
		- q1.vector.y * q2.vector.x
		+ q1.vector.z * q2.scalar
	});
}

t_vec3	ft_quaternion_rot(t_vec3 vec, t_vec3 axis, float angle)
{
	t_quaternion	p;
	t_quaternion	q;
	t_quaternion	q_inv;
	t_quaternion	p_rotated;

	p.scalar = 0;
	p.vector = vec;
	q.scalar = cos(angle / 2);
	q.vector = ft_vec3_scale(axis, sin(angle / 2));
	q_inv.scalar = q.scalar;
	q_inv.vector = ft_vec3_scale(q.vector, -1);
	p_rotated = ft_quaternion_mult(ft_quaternion_mult(q, p), q_inv);
	return (p_rotated.vector);
}

t_vec3	ft_vec3_rotate_x(const t_vec3 vec, float roll)
{
	const t_vec3	x_axis = (t_vec3){1, 0, 0};

	return (ft_quaternion_rot(vec, x_axis, roll));
}

t_vec3	ft_vec3_rotate_y(const t_vec3 vec, float pitch)
{
	const t_vec3	y_axis = (t_vec3){0, 1, 0};

	return (ft_quaternion_rot(vec, y_axis, pitch));
}

t_vec3	ft_vec3_rotate_z(const t_vec3 vec, float yaw)
{
	const t_vec3	z_axis = (t_vec3){0, 0, 1};

	return (ft_quaternion_rot(vec, z_axis, yaw));
}
