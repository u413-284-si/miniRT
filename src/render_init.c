/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 16:42:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_err	ft_init_window(t_render *render, t_image *screen, bool fullscreen)
{
	int	size[2];

	if (ft_err_mlx_init((void**)&render->mlx_ptr))
		return (ERROR);
	if (fullscreen)
		ft_set_fullscreen(render, screen);
	size[0] = screen->image_width;
	size[1] = screen->image_height;
	if (ft_err_mlx_new_window((void**)&render->win_ptr, render->mlx_ptr, size, "miniRT"))
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
	mlx_get_screen_size(render->mlx_ptr, &screen->image_width, &screen->image_height);
	ft_printf("🖥️  Screen size\n   |%d x %d|\n\n", screen->image_width, screen->image_height);
}

t_err	ft_init_image(t_render *render, int size[2])
{
	if (ft_err_mlx_new_image((void**)&render->buffer, render->mlx_ptr, size))
		return (ERROR);
	render->buffer.addr = mlx_get_data_addr(render->buffer.ptr, &render->buffer.bpp,
		&render->buffer.line_len, &render->buffer.endian);
	render->buffer.bytes = render->buffer.bpp / 8;
	if (render->buffer.endian)
		ft_printf("🥚 Endian\n   |big|\n\n");
	else
		ft_printf("🥚 Endian\n   |little|\n\n");
	return (SUCCESS);
}
