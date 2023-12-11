/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:54:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/07 21:47:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

float	ft_quat_len(t_quat quat)
{
	return (sqrtf(quat.x * quat.x + quat.y * quat.y
			+ quat.z * quat.z + quat.w * quat.w));
}

t_quat	ft_quat_norm(t_quat quat)
{
	float	len;

	len = ft_quat_len(quat);
	quat.x /= len;
	quat.y /= len;
	quat.z /= len;
	quat.w /= len;
	return (quat);
}

t_quat	ft_quat_conjugate(t_quat quat)
{
	quat.x = -quat.x;
	quat.y = -quat.y;
	quat.z = -quat.z;
	return (quat);
}

t_quat	ft_quat_mult(t_quat a, t_quat b)
{
	t_quat	c;

	c.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	c.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	c.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	c.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	return (c);
}

t_quat	ft_quat_cross(t_quat q1, t_quat q2)
{
	return ((t_quat){
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
		q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x});
}

// builds a quaternion from an angle and an axis
t_quat	ft_quat_angle_axis(float angle, t_vec3 axis)
{
	t_quat	ret;
	float	half_angle;

	half_angle = angle * 0.5;
	ret.x = axis.x * sin(half_angle);
	ret.y = axis.y * sin(half_angle);
	ret.z = axis.z * sin(half_angle);
	ret.w = cos(half_angle);
	return (ft_quat_norm(ret));
}

// from https://stackoverflow.com/questions/62937791/quaternion-based-point-rotations-using-glm
t_vec3	ft_quat_rotate(t_quat q, t_vec3 v)
{
	t_vec3	quatvec;
	t_vec3	uv;
	t_vec3	uuv;

	quatvec = ft_vec3_create(q.x, q.y, q.z);
	uv = ft_vec3_cross(quatvec, v);
	uuv = ft_vec3_cross(quatvec, uv);

	return (ft_vec3_add(v,
			(ft_vec3_scale(ft_vec3_add(ft_vec3_scale(uv, q.w), uuv), 2))));
}

t_vec3	ft_quat_rotate2(float angle, t_vec3 axis, t_vec3 vector)
{
	const float		radian_angle = ft_degree_to_radian(angle);
	const t_quat	v_quat = (t_quat){vector.x, vector.y, vector.z, 0};
	const t_quat	quat_rot = ft_quat_angle_axis(radian_angle, axis);
	const t_quat	quat_rot_conj = ft_quat_conjugate(quat_rot);
	const t_quat	rot_quat = ft_quat_cross(ft_quat_cross(quat_rot, v_quat), quat_rot_conj);

	return ((t_vec3){rot_quat.x, rot_quat.y, rot_quat.z});
}
