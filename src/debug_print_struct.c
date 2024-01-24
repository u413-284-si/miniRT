/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:25:48 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/20 13:44:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_print.h"

void	ft_print_vec3(const t_vec3 vec)
{
	printf("x: %.6f, y: %.6f, z: %.6f\n", vec.x, vec.y, vec.z);
}

void	ft_print_mat4(const t_mat4 mat)
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

void	ft_print_colour(const t_colour col)
{
	printf("r: %.6f, g: %.6f, b: %.6f\n", col.r, col.g, col.b);
}
