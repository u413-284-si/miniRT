/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:42:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 16:42:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

// is in column major form
// angle is in rad
t_mat4	ft_mat4_perspective(float angle, float ratio, float near, float far)
{
	const float	fov_vertical = 2 * atanf(tanf(angle / 2) / ratio);
	t_mat4		mat;

	mat = ft_mat4_set_identity();
	mat.mat[0][0] = 1.0 / tanf(angle / 2);
	mat.mat[1][1] = 1.0 / tanf(fov_vertical / 2);
	mat.mat[2][2] = -((far + near) / (far - near));
	mat.mat[2][3] = -1.0;
	mat.mat[3][2] = -((2 * far * near) / (far - near));
	return (mat);
}

// inverse could easily be calculated
t_mat4	ft_mat4_cam_look_at(t_vec3 cam_pos, t_vec3 cam_dir, t_vec3 v_up)
{
	t_vec3	cam_right;
	t_vec3	cam_up;
	t_mat4	mat;

	cam_right = ft_vec3_norm(ft_vec3_cross(cam_dir, v_up));
	cam_up = ft_vec3_cross(cam_right, cam_dir);
	mat = ft_mat4_set_identity();
	mat.mat[0][0] = cam_right.x;
	mat.mat[1][0] = cam_right.y;
	mat.mat[2][0] = cam_right.z;
	mat.mat[0][1] = cam_up.x;
	mat.mat[1][1] = cam_up.y;
	mat.mat[2][1] = cam_up.z;
	mat.mat[0][2] = -cam_dir.x;
	mat.mat[1][2] = -cam_dir.y;
	mat.mat[2][2] = -cam_dir.z;
	mat.mat[0][3] = cam_pos.x;
	mat.mat[1][3] = cam_pos.y;
	mat.mat[2][3] = cam_pos.z;
	return (mat);
}
