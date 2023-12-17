/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:49:59 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/17 09:54:08 by gwolf            ###   ########.fr       */
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
