/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:42:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 11:05:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	ft_mat4_perspective(float hfov, float ratio, float near, float far)
{
	const float	vfov = 2 * atanf(tanf(hfov / 2) / ratio);
	t_mat4		mat;

	mat = ft_mat4_set_identity();
	mat.mat[0][0] = 1.0 / tanf(hfov / 2);
	mat.mat[1][1] = 1.0 / tanf(vfov / 2);
	mat.mat[2][2] = -((far + near) / (far - near));
	mat.mat[2][3] = -1.0;
	mat.mat[3][2] = -((2 * far * near) / (far - near));
	mat.mat[3][3] = 0;
	return (mat);
}

t_mat4	ft_mat4_cam_look_at(t_vec3 position, t_vec3 target, t_vec3 world_up)
{
	t_vec3	cam_direction;
	t_vec3	cam_right;
	t_vec3	cam_up;
	t_mat4	ret;

	cam_direction = ft_vec3_norm(ft_vec3_sub(target, position));
	cam_right = ft_vec3_norm(ft_vec3_cross(cam_direction, world_up));
	cam_up = ft_vec3_cross(cam_right, cam_direction);

	ret = ft_mat4_set_identity();

	ret.mat[0][0] = cam_right.x;
	ret.mat[1][0] = cam_right.y;
	ret.mat[2][0] = cam_right.z;
	ret.mat[0][1] = cam_up.x;
	ret.mat[1][1] = cam_up.y;
	ret.mat[2][1] = cam_up.z;
	ret.mat[0][2] = -cam_direction.x;
	ret.mat[1][2] = -cam_direction.y;
	ret.mat[2][2] = -cam_direction.z;
	ret.mat[3][0] = -ft_vec3_dot(cam_right, position);
	ret.mat[3][1] = -ft_vec3_dot(cam_up, position);
	ret.mat[3][2] = ft_vec3_dot(cam_direction, position);

	return (ret);
}
