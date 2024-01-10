/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:00:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/20 11:35:44 by gwolf            ###   ########.fr       */
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
