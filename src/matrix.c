/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:00:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/07 21:22:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "ft_print.h"

t_vec4	ft_vec4_create(float x, float y, float z, float w)
{
	t_vec4	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.w = w;
	return (ret);
}

t_vec3	ft_vec3_create(float x, float y, float z)
{
	t_vec3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec4	ft_mult_vec4_mat4(t_vec4 vec, t_mat4 mat)
{
	t_vec4	result;

	result.x = vec.x * mat[0][0]
		+ vec.y * mat[1][0]
		+ vec.z * mat[2][0]
		+ vec.w * mat[3][0];
	result.y = vec.x * mat[0][1]
		+ vec.y * mat[1][1]
		+ vec.z * mat[2][1]
		+ vec.w * mat[3][1];
	result.z = vec.x * mat[0][2]
		+ vec.y * mat[1][2]
		+ vec.z * mat[2][2]
		+ vec.w * mat[3][2];
	result.w = vec.x * mat[0][3]
		+ vec.y * mat[1][3]
		+ vec.z * mat[2][3]
		+ vec.w * mat[3][3];
	return (result);
}

// inverse could easily be calculated
void	ft_mat4_cam_look_at(t_mat4 mat, t_vec3 cam_pos, t_vec3 cam_dir, t_vec3 v_up)
{
	t_vec3	cam_right;
	t_vec3	cam_up;

	cam_right = ft_vec3_norm(ft_vec3_cross(cam_dir, v_up));
	cam_up = ft_vec3_cross(cam_right, cam_dir);
	ft_mat4_set_identity(mat);
	mat[0][0] = cam_right.x;
	mat[1][0] = cam_right.y;
	mat[2][0] = cam_right.z;
	mat[0][1] = cam_up.x;
	mat[1][1] = cam_up.y;
	mat[2][1] = cam_up.z;
	mat[0][2] = -cam_dir.x;
	mat[1][2] = -cam_dir.y;
	mat[2][2] = -cam_dir.z;
	mat[0][3] = cam_pos.x;
	mat[1][3] = cam_pos.y;
	mat[2][3] = cam_pos.z;
	return ;
}

// is in column major form
// angle is in rad
void	ft_mat4_perspective(t_mat4 mat, float angle, float ratio, float near, float far)
{
	const float	fov_vertical = 2 * atanf(tanf(angle / 2) / ratio);

	ft_mat4_set_identity(mat);
	mat[0][0] = 1.0 / tanf(angle / 2);
	mat[1][1] = 1.0 / tanf(fov_vertical / 2);
	mat[2][2] = -((far + near) / (far - near));
	mat[2][3] = -1.0;
	mat[3][2] = -((2 * far * near) / (far - near));
}

void	ft_mat4_copy(const t_mat4 src, t_mat4 dst)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void	ft_mat4_set_identity(t_mat4 mat)
{
	static const t_mat4	identity = {
	{1.0f, 0.0f, 0.0f, 0.0f},
	{0.0f, 1.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 1.0f, 0.0f},
	{0.0f, 0.0f, 0.0f, 1.0f}
	};

	ft_mat4_copy(identity, mat);
}

void printMatrix(t_mat4 mat)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.2f\t", mat[i][j]);
		}
		printf("\n");
	}
}