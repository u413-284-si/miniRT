/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:00:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/30 18:29:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// is in column major form
// angle is in rad
void	ft_mat4_perspective(t_mat4 mat, float angle, float ratio, float near, float far)
{
	float	tan_half_angle;

	ft_mat4_set_identity(mat);
	tan_half_angle = tan(angle / 2);
	mat[0][0] = 1 / (ratio * tan_half_angle);
	mat[1][1] = 1 / (tan_half_angle);
	mat[2][2] = -(far + near) / (far - near);
	mat[3][2] = -1;
	mat[2][3] = -(2 * far * near) / (far - near);
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
