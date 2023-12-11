/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:55:14 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 16:36:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

/* ====== LIBRARIES ====== */

# include <math.h>
# include "vec3.h"
# include "mat4.h"

/* ====== TYPEDEFS ====== */

typedef struct s_quat {
	float x;
	float y;
	float z;
	float w;
}	t_quat;

/* ====== FUNCTIONS ====== */

float	ft_quat_len(t_quat quat);
t_quat	ft_quat_norm(t_quat quat);
t_quat	ft_quat_conjugate(t_quat quat);
t_quat	ft_quat_mult(t_quat a, t_quat b);
t_quat	ft_quat_cross(t_quat q1, t_quat q2);
t_quat	ft_quat_angle_axis(float angle, t_vec3 axis);
t_vec3	ft_quat_rotate(t_quat q, t_vec3 v);
t_vec3	ft_quat_rotate2(float angle, t_vec3 axis, t_vec3 vector);


#endif