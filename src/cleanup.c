/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 14:51:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	ft_free_char_arr(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free (array);
}

void	ft_free_mlx(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	if (img_ptr)
		mlx_destroy_image(mlx_ptr, img_ptr);
	if (win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
	if (mlx_ptr)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
}