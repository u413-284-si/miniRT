/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:49:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 17:14:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	ft_mat4_create_rotate_x(float roll)
{
	t_mat4	rot_x;
	float	roll_sin;
	float	roll_cos;

	roll_sin = sin(ft_degree_to_radian(roll));
	roll_cos = cos(ft_degree_to_radian(roll));
	rot_x = ft_mat4_set_identity();
	rot_x.mat[0][0] = 1;
	rot_x.mat[1][1] = roll_cos;
	rot_x.mat[1][2] = roll_sin;
	rot_x.mat[2][1] = -roll_sin;
	rot_x.mat[2][2] = roll_cos;
	rot_x.mat[3][3] = 1;
	return (rot_x);
}

t_mat4	ft_mat4_create_rotate_y(float pitch)
{
	t_mat4	rot_y;
	float	pitch_sin;
	float	pitch_cos;

	pitch_sin = sin(ft_degree_to_radian(pitch));
	pitch_cos = cos(ft_degree_to_radian(pitch));
	rot_y = ft_mat4_set_identity();
	rot_y.mat[0][0] = pitch_cos;
	rot_y.mat[0][2] = -pitch_sin;
	rot_y.mat[1][1] = 1;
	rot_y.mat[2][0] = pitch_sin;
	rot_y.mat[2][2] = pitch_cos;
	rot_y.mat[3][3] = 1;
	return (rot_y);
}

t_mat4	ft_mat4_create_rotate_z(float yaw)
{
	t_mat4	rot_z;
	float	yaw_sin;
	float	yaw_cos;

	yaw_sin = sin(ft_degree_to_radian(yaw));
	yaw_cos = cos(ft_degree_to_radian(yaw));
	rot_z = ft_mat4_set_identity();
	rot_z.mat[0][0] = yaw_cos;
	rot_z.mat[0][1] = yaw_sin;
	rot_z.mat[1][0] = -yaw_sin;
	rot_z.mat[1][1] = yaw_cos;
	rot_z.mat[2][2] = 1;
	rot_z.mat[3][3] = 1;
	return (rot_z);
}
