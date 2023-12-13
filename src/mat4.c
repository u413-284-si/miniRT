/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:00:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/13 15:34:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "ft_print.h"

t_mat4	ft_mat4_set_identity(void)
{
	static const t_mat4	identity = {
		.mat[0][0] = 1.0f,
		.mat[1][1] = 1.0f,
		.mat[2][2] = 1.0f,
		.mat[3][3] = 1.0f
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

t_mat4	ft_mat4_mult_mat4(const t_mat4 left, const t_mat4 right)
{
	t_mat4	ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret.mat[j][i] = 0;
			k = 0;
			while (k < 4)
			{
				ret.mat[j][i] += left.mat[k][j] * right.mat[i][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

void	ft_mat4_print(t_mat4 mat)
{
	int	col;
	int	row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			printf("%.2f\t", mat.mat[row][col]);
			row++;
		}
		printf("\n");
		col++;
	}
}
