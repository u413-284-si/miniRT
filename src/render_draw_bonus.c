/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 15:42:48 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ft_put_pix_to_image(t_img *img, int x, int y, int color)
{
	int		i;
	char	*pixel;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * img->bytes);
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_render_image(t_render *render)
{
	int			iterate[2];
	t_colour	pixel_colour;
	int			colour;

	iterate[1] = -1;
	while (++iterate[1] < render->mlx_ptrs.img.height)
	{
		iterate[0] = -1;
		while (++iterate[0] < render->mlx_ptrs.img.width)
		{
			pixel_colour = ft_sample_down(ft_get_colour(iterate, render->vp, \
				render->cam, render->scene), render->cam.samples_per_pixel);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->mlx_ptrs.img, iterate[0], \
				iterate[1], colour);
		}
	}
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
		render->mlx_ptrs.img.ptr, 0, 0);
}
