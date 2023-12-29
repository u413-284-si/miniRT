/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vec3_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:28:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/28 13:28:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4_vec3.h"

t_vec3	ft_vec3_mult_mat4(const t_mat4 mat, const t_vec3 vec)
{
	t_vec3	result;

	result.x
		= vec.x * mat.mat[0][0]
		+ vec.y * mat.mat[1][0]
		+ vec.z * mat.mat[2][0]
		+ mat.mat[3][0];
	result.y
		= vec.x * mat.mat[0][1]
		+ vec.y * mat.mat[1][1]
		+ vec.z * mat.mat[2][1]
		+ mat.mat[3][1];
	result.z
		= vec.x * mat.mat[0][2]
		+ vec.y * mat.mat[1][2]
		+ vec.z * mat.mat[2][2]
		+ mat.mat[3][2];
	return (result);
}

t_vec3	ft_vec3_rotate_x(const t_vec3 vec, float roll)
{
	t_mat4	rot_x;
	t_vec3	result;

	rot_x = ft_mat4_create_rotate_x(roll);
	result = ft_vec3_mult_mat4(rot_x, vec);
	result = ft_vec3_norm(result);
	return (result);
}

t_vec3	ft_vec3_rotate_y(const t_vec3 vec, float pitch)
{
	t_mat4	rot_y;
	t_vec3	result;

	rot_y = ft_mat4_create_rotate_y(pitch);
	result = ft_vec3_mult_mat4(rot_y, vec);
	result = ft_vec3_norm(result);
	return (result);
}

t_vec3	ft_vec3_rotate_z(const t_vec3 vec, float yaw)
{
	t_mat4	rot_z;
	t_vec3	result;

	rot_z = ft_mat4_create_rotate_z(yaw);
	result = ft_vec3_mult_mat4(rot_z, vec);
	result = ft_vec3_norm(result);
	return (result);
}
