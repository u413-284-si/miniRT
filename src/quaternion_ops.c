/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:54:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/27 10:13:47 by gwolf            ###   ########.fr       */
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
