/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/19 22:35:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_err	ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, t_image *image, bool fullscreen)
{
	int	size[2];

	if (ft_err_mlx_init((void **)&mlx_ptrs->mlx_ptr))
		return (ERROR);
	if (fullscreen)
		ft_set_fullscreen(mlx_ptrs, image);
	size[0] = image->image_width;
	size[1] = image->image_height;
	if (ft_err_mlx_new_window((void **)&mlx_ptrs->win_ptr,
			mlx_ptrs->mlx_ptr, size, "miniRT"))
	{
		ft_free_mlx(mlx_ptrs->mlx_ptr, NULL, NULL);
		return (ERROR);
	}
	if (ft_init_image(mlx_ptrs, size))
	{
		ft_free_mlx(mlx_ptrs->mlx_ptr, NULL, NULL);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_set_fullscreen(t_mlx_ptrs *mlx_ptrs, t_image *image)
{
	mlx_get_screen_size(mlx_ptrs->mlx_ptr, &image->image_width, &image->image_height);
}

t_err	ft_init_image(t_mlx_ptrs *mlx_ptrs, int size[2])
{
	if (ft_err_mlx_new_image((void **)&mlx_ptrs->img, mlx_ptrs->mlx_ptr, size))
		return (ERROR);
	mlx_ptrs->img.addr = mlx_get_data_addr(mlx_ptrs->img.ptr,
			&mlx_ptrs->img.bpp, &mlx_ptrs->img.line_len,
			&mlx_ptrs->img.endian);
	mlx_ptrs->img.bytes = mlx_ptrs->img.bpp / 8;
	return (SUCCESS);
}
