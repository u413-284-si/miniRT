/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:26:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/29 19:48:04 by sqiu             ###   ########.fr       */
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

void	ft_row_operation(t_mat4 *matrix, int i, int j, float factor)
{
	int	k;

	k = -1;
	while (++k < 4)
		matrix->mat[k][i] -= factor * matrix->mat[k][j];
}

// Function to invert the matrix
void	ft_invert_matrix(t_mat4 matrix, t_mat4 *inverse)
{
	int		i;
	int		j;
	float	pivot;
	float	factor;

	i = 0;
	j = 0;
	*inverse = ft_mat4_set_identity();
	while (i < 4)
	{
		pivot = matrix.mat[i][i];
		j = 0;
		while (j < 4)
		{
			matrix.mat[j][i] /= pivot;
			inverse->mat[j][i] /= pivot;
			j++;
		}
		j = 0;
		while (j < 4)
		{
			if (i != j)
			{
				factor = matrix.mat[i][j];
				ft_row_operation(&matrix, i, j, factor);
				ft_row_operation(inverse, i, j, factor);
			}
			j++;
		}
		i++;
	}
}
