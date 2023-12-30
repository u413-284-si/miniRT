/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:26:59 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/29 22:04:44 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometric_transform_bonus.h"

void	ft_set_transform(t_vec3 translation, t_vec3 rotation, t_vec3 scale, \
	t_mat4 *result)
{
	t_mat4	transl_matrix;
	t_mat4	rot_x_matrix;
	t_mat4	rot_y_matrix;
	t_mat4	rot_z_matrix;
	t_mat4	scale_matrix;

	transl_matrix = ft_mat4_set_identity();
	rot_x_matrix = ft_mat4_set_identity();
	rot_y_matrix = ft_mat4_set_identity();
	rot_z_matrix = ft_mat4_set_identity();
	scale_matrix = ft_mat4_set_identity();
	transl_matrix.mat[3][0] = translation.x;
	transl_matrix.mat[3][1] = translation.y;
	transl_matrix.mat[3][2] = translation.z;
	ft_set_rotation_matrices(&rot_x_matrix, &rot_x_matrix, &rot_z_matrix,
		rotation);
	scale_matrix.mat[0][0] = scale.x;
	scale_matrix.mat[1][1] = scale.y;
	scale_matrix.mat[2][2] = scale.z;
	*result = ft_mat4_mult_mat4(ft_mat4_mult_mat4(ft_mat4_mult_mat4(\
		ft_mat4_mult_mat4(scale_matrix, transl_matrix), \
		rot_z_matrix), rot_y_matrix), rot_x_matrix);
}

void	ft_set_rotation_matrices(t_mat4 *rot_x_matrix, t_mat4 *rot_y_matrix, \
	t_mat4 *rot_z_matrix, t_vec3 rotation)
{
	rot_z_matrix->mat[0][0] = cos(rotation.z);
	rot_z_matrix->mat[1][0] = -sin(rotation.z);
	rot_z_matrix->mat[0][1] = sin(rotation.z);
	rot_z_matrix->mat[1][1] = cos(rotation.z);
	rot_y_matrix->mat[0][0] = cos(rotation.y);
	rot_y_matrix->mat[2][0] = sin(rotation.y);
	rot_y_matrix->mat[0][2] = -sin(rotation.y);
	rot_y_matrix->mat[2][2] = cos(rotation.y);
	rot_x_matrix->mat[1][1] = cos(rotation.x);
	rot_x_matrix->mat[2][1] = -sin(rotation.x);
	rot_x_matrix->mat[1][2] = sin(rotation.x);
	rot_x_matrix->mat[2][2] = cos(rotation.x);
}

t_ray	ft_transform_ray(t_ray input, bool dir_flag, t_mat4 fwd, t_mat4 bck)
{
	t_ray	output;

	output.origin = ft_transform_vec3(input.origin, dir_flag, fwd, bck);
	output.direction = ft_transform_vec3(input.direction, dir_flag, fwd, bck);
	return (output);
}

t_vec3	ft_transform_vec3(t_vec3 input, bool dir_flag, t_mat4 fwd, t_mat4 bck)
{
	t_vec3	output;

	if (dir_flag)
		output = ft_vec3_mult_mat4(fwd, input);
	else
		output = ft_vec3_mult_mat4(bck, input);
	return (output);
}

t_vec3	ft_get_rotation_vec3(t_vec3 orientation)
{
	t_vec3	rotation;

	rotation.x = atan2f(orientation.y, orientation.z);
	rotation.y = atan2f(orientation.x, sqrtf(powf(orientation.y, 2.0) + \
		powf(orientation.z, 2.0)));
	rotation.z = 0.0;
	return (rotation);
}
