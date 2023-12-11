/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:52:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 16:45:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

static void	swap_rows(t_mat4 *mat, int row1, int row2)
{
	int		i;
	float	temp;

	i = 0;
	while (i < 4)
	{
		temp = mat->mat[row1][i];
		mat->mat[row1][i] = mat->mat[row2][i];
		mat->mat[row2][i] = temp;
		i++;
	}
}

static int	find_non_zero_and_swap(t_mat4 *mat, t_mat4 *inverse, int i)
{
	int	k;

	k = i + 1;
	while (k < 4)
	{
		if (mat->mat[k][i] != 0.0f)
		{
			swap_rows(mat, i, k);
			swap_rows(inverse, i, k);
			return (1);
		}
		++k;
	}
	return (0);
}

static void	normalize_row(t_mat4 *mat, t_mat4 *inverse, int row, float divisor)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		mat->mat[row][j] /= divisor;
		inverse->mat[row][j] /= divisor;
		++j;
	}
}

static void	eliminate_non_diagonal(t_mat4 *mat, t_mat4 *inverse, int i)
{
	int		k;
	int		j;
	float	factor;

	k = 0;
	while (k < 4)
	{
		if (k != i)
		{
			factor = mat->mat[k][i];
			j = 0;
			while (j < 4)
			{
				mat->mat[k][j] -= factor * mat->mat[i][j];
				inverse->mat[k][j] -= factor * inverse->mat[i][j];
				++j;
			}
		}
		++k;
	}
}

t_mat4	ft_mat4_inverse(t_mat4 mat)
{
	t_mat4	inverse;
	int		i;

	inverse = ft_mat4_set_identity();
	i = 0;
	while (i < 4)
	{
		if (mat.mat[i][i] == 0.0f)
		{
			if (!find_non_zero_and_swap(&mat, &inverse, i))
			{
				ft_perror("Matrix is singular, cannot find its inverse.", 0);
				return (ft_mat4_set_identity());
			}
		}
		normalize_row(&mat, &inverse, i, mat.mat[i][i]);
		eliminate_non_diagonal(&mat, &inverse, i);
		++i;
	}
	return (inverse);
}
