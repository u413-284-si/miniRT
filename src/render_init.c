/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/15 14:24:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_err	ft_init_renderer(t_render *render, t_image *screen, bool fullscreen)
{
	int	size[2];

	if (ft_err_mlx_init((void **)&render->mlx_ptr))
		return (ERROR);
	if (fullscreen)
		ft_set_fullscreen(render, screen);
	size[0] = screen->width;
	size[1] = screen->height;
	if (ft_err_mlx_new_window((void **)&render->win_ptr,
			render->mlx_ptr, size, "miniRT"))
	{
		ft_free_mlx(render->mlx_ptr, NULL, NULL);
		return (ERROR);
	}
	if (ft_init_image(render, size))
	{
		ft_free_mlx(render->mlx_ptr, NULL, NULL);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_set_fullscreen(t_render *render, t_image *screen)
{
	mlx_get_screen_size(render->mlx_ptr, &screen->width, &screen->height);
}

t_err	ft_init_image(t_render *render, int size[2])
{
	if (ft_err_mlx_new_image((void **)&render->buffer, render->mlx_ptr, size))
		return (ERROR);
	render->buffer.addr = mlx_get_data_addr(render->buffer.ptr,
			&render->buffer.bpp, &render->buffer.line_len,
			&render->buffer.endian);
	render->buffer.bytes = render->buffer.bpp / 8;
	return (SUCCESS);
}
