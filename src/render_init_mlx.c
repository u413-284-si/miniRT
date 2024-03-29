/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:10 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 10:17:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_err	ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, t_vec2i *win_size)
{
	if (ft_err_mlx_init((void **)&mlx_ptrs->mlx_ptr))
		return (ERROR);
	*win_size = ft_check_screen_size(mlx_ptrs->mlx_ptr, *win_size);
	if (ft_err_mlx_new_window((void **)&mlx_ptrs->win_ptr,
			mlx_ptrs->mlx_ptr, *win_size, "miniRT"))
	{
		ft_free_mlx(mlx_ptrs);
		return (ERROR);
	}
	if (ft_init_image(mlx_ptrs, *win_size))
	{
		ft_free_mlx(mlx_ptrs);
		return (ERROR);
	}
	return (SUCCESS);
}

t_vec2i	ft_check_screen_size(void *mlx_ptr, t_vec2i win_size)
{
	t_vec2i	screen_size;

	mlx_get_screen_size(mlx_ptr, &screen_size.x, &screen_size.y);
	if (win_size.x > screen_size.x)
		win_size.x = screen_size.x;
	if (win_size.y > screen_size.y)
		win_size.y = screen_size.y;
	return (win_size);
}

t_err	ft_init_image(t_mlx_ptrs *mlx_ptrs, t_vec2i size)
{
	if (ft_err_mlx_new_image((void **)&mlx_ptrs->img, mlx_ptrs->mlx_ptr, size))
		return (ERROR);
	mlx_ptrs->img.addr = mlx_get_data_addr(mlx_ptrs->img.ptr,
			&mlx_ptrs->img.bpp, &mlx_ptrs->img.line_len,
			&mlx_ptrs->img.endian);
	mlx_ptrs->img.bytes = mlx_ptrs->img.bpp / 8;
	mlx_ptrs->img.size = size;
	size = (t_vec2i){MENU_WIDTH, size.y};
	if (ft_err_mlx_new_image((void **)&mlx_ptrs->veil, mlx_ptrs->mlx_ptr, size))
	{
		mlx_destroy_image(mlx_ptrs->mlx_ptr, mlx_ptrs->img.ptr);
		return (ERROR);
	}
	mlx_ptrs->veil.addr = mlx_get_data_addr(mlx_ptrs->veil.ptr,
			&mlx_ptrs->veil.bpp, &mlx_ptrs->veil.line_len,
			&mlx_ptrs->veil.endian);
	mlx_ptrs->veil.bytes = mlx_ptrs->veil.bpp / 8;
	mlx_ptrs->veil.size = size;
	return (SUCCESS);
}
