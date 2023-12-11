/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:00:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 16:44:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "ft_print.h"

t_mat4	ft_mat4_set_identity(void)
{
	static const t_mat4	identity = {
	{1.0f, 0.0f, 0.0f, 0.0f},
	{0.0f, 1.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 1.0f, 0.0f},
	{0.0f, 0.0f, 0.0f, 1.0f}
	};

	return (identity);
}

t_mat4	ft_mat4_copy(const t_mat4 src)
{
	int		i;
	int		j;
	t_mat4	ret;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret.mat[i][j] = src.mat[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}

t_vec4	ft_mat4_mult_vec4(const t_mat4 mat, const t_vec4 vec)
{
	t_vec4	result;

	result.x
		= vec.x * mat.mat[0][0]
		+ vec.y * mat.mat[1][0]
		+ vec.z * mat.mat[2][0]
		+ vec.w * mat.mat[3][0];
	result.y
		= vec.x * mat.mat[0][1]
		+ vec.y * mat.mat[1][1]
		+ vec.z * mat.mat[2][1]
		+ vec.w * mat.mat[3][1];
	result.z
		= vec.x * mat.mat[0][2]
		+ vec.y * mat.mat[1][2]
		+ vec.z * mat.mat[2][2]
		+ vec.w * mat.mat[3][2];
	result.w
		= vec.x * mat.mat[0][3]
		+ vec.y * mat.mat[1][3]
		+ vec.z * mat.mat[2][3]
		+ vec.w * mat.mat[3][3];
	return (result);
}

void	ft_mat4_print(t_mat4 mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%.2f\t", mat.mat[i][j]);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
