/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_mlx_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 14:51:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

t_err	ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, bool fullscreen)
{
	int	win_size[2];

	if (ft_err_mlx_init((void **)&mlx_ptrs->mlx_ptr))
		return (ERROR);
	if (fullscreen)
		ft_set_fullscreen(mlx_ptrs->mlx_ptr, win_size);
	else
	{
		win_size[0] = WIN_SIZE_X;
		win_size[1] = WIN_SIZE_Y;
	}
	if (ft_err_mlx_new_window((void **)&mlx_ptrs->win_ptr,
			mlx_ptrs->mlx_ptr, win_size, "miniRT"))
	{
		ft_free_mlx(mlx_ptrs->mlx_ptr, NULL, NULL);
		return (ERROR);
	}
	if (ft_init_image(mlx_ptrs, win_size))
	{
		ft_free_mlx(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr, NULL);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_set_fullscreen(void *mlx_ptr, int win_size[2])
{
	mlx_get_screen_size(mlx_ptr, &win_size[0], &win_size[0]);
}

t_err	ft_init_image(t_mlx_ptrs *mlx_ptrs, int size[2])
{
	if (ft_err_mlx_new_image((void **)&mlx_ptrs->img, mlx_ptrs->mlx_ptr, size))
		return (ERROR);
	mlx_ptrs->img.addr = mlx_get_data_addr(mlx_ptrs->img.ptr,
			&mlx_ptrs->img.bpp, &mlx_ptrs->img.line_len,
			&mlx_ptrs->img.endian);
	mlx_ptrs->img.bytes = mlx_ptrs->img.bpp / 8;
	mlx_ptrs->img.width = size[0];
	mlx_ptrs->img.height = size[1];
	return (SUCCESS);
}
