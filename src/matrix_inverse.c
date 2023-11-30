/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:52:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/30 08:50:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	swap_rows(t_mat4 mat, int row1, int row2)
{
	int		i;
	float	temp;

	i = 0;
	while (i < 4)
	{
		temp = mat[row1][i];
		mat[row1][i] = mat[row2][i];
		mat[row2][i] = temp;
		i++;
	}
}

static int	find_non_zero_and_swap(t_mat4 inv, t_mat4 identity, int i)
{
	int	k;

	k = i + 1;
	while (k < 4)
	{
		if (inv[k][i] != 0.0f)
		{
			ft_mat_swap_rows(inv, i, k);
			ft_mat_swap_rows(identity, i, k);
			return (1);
		}
		++k;
	}
	return (0);
}

static void	normalize_row(t_mat4 inv, t_mat4 identity, int row, float divisor)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		inv[row][j] /= divisor;
		identity[row][j] /= divisor;
		++j;
	}
}

static void	eliminate_non_diagonal(t_mat4 inv, t_mat4 identity, int i)
{
	int		k;
	int		j;
	float	factor;

	k = 0;
	while (k < 4)
	{
		if (k != i)
		{
			factor = inv[k][i];
			j = 0;
			while (j < 4)
			{
				inv[k][j] -= factor * inv[i][j];
				identity[k][j] -= factor * identity[i][j];
				++j;
			}
		}
		++k;
	}
}

int	ft_inverse_matrix(const t_mat4 mat, t_mat4 inv)
{
	t_mat4	identity;
	int		i;

	ft_mat4_set_identity(identity);
	ft_mat4_copy(mat, inv);
	i = 0;
	while (i < 4)
	{
		if (inv[i][i] == 0.0f)
		{
			if (!find_non_zero_and_swap(inv, identity, i))
			{
				ft_perror("Matrix is singular, cannot find its inverse.", 0);
				return (1);
			}
		}
		normalize_row(inv, identity, i, inv[i][i]);
		eliminate_non_diagonal(inv, identity, i);
		++i;
	}
	ft_mat4_copy(identity, inv);
	return (0);
}
