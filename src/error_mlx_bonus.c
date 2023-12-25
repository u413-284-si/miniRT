/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:04:04 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 13:38:08 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_mlx_bonus.h"

t_err	ft_err_mlx_init(void **ptr)
{
	errno = 0;
	*ptr = mlx_init();
	if (*ptr == NULL)
	{
		ft_perror("mlx_init() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_err_mlx_new_window(void **ptr, void *mlx_ptr, int size[2],\
	char *title)
{
	errno = 0;
	*ptr = mlx_new_window(mlx_ptr, size[0], size[1], title);
	if (*ptr == NULL)
	{
		ft_perror("mlx_new_window() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_err_mlx_new_image(void **ptr, void *mlx_ptr, int size[2])
{
	errno = 0;
	*ptr = mlx_new_image(mlx_ptr, size[0], size[1]);
	if (*ptr == NULL)
	{
		ft_perror("mlx_new_image() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}
