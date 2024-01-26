/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_text_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 00:18:51 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put_bonus.h"

static t_vec2i	ft_put_header(t_putinfo put, uint32_t options,
		uint64_t last_render_time)
{
	put.pos = ft_put_mode(put, options);
	if (!ft_option_isset(options, O_SHOW_CTRL))
	{
		put.pos = ft_put_inc(put, options);
		put.pos = ft_put_time(put, last_render_time, \
			ft_option_isset(options, O_SHOW_FPS));
	}
	put.pos.x -= 15;
	put.pos = ft_put_str_and_advance(put, "------------------------");
	put.pos.x += 15;
	put.pos.y += Y_HALF_LINE;
	return (put.pos);
}

static t_vec2i	ft_put_footer(t_putinfo put, uint32_t options, int img_height)
{
	put.pos.y = img_height - Y_MENU_BOTTOM_SMALL;
	put.pos.x -= 15;
	put.pos = ft_put_str_and_advance(put, "-------General----------");
	put.pos.x += 15;
	if (!ft_option_isset(options, O_SHOW_OPTIONS))
		put.pos = ft_put_str_and_advance(put, "O:     Show options");
	else
		put.pos = ft_put_str_and_advance(put, "O:     Hide options");
	if (!ft_option_isset(options, O_SHOW_CTRL))
		put.pos = ft_put_str_and_advance(put, "Shift: Show controls");
	else
		put.pos = ft_put_str_and_advance(put, "Shift: Hide controls");
	put.pos = ft_put_str_and_advance(put, "ESC:   Exit");
	return (put.pos);
}

void	ft_menu_put_text(t_render *render)
{
	t_putinfo	put;

	put.mlx_ptrs = render->mlx_ptrs;
	put.pos = (t_vec2i){X_MENU_OFFSET, Y_MENU_TOP};
	put.col = render->menu.font_col;
	if (!ft_option_isset(render->options, O_SHOW_MENU))
		return (ft_put_str(put, "Press I to show menu"));
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
		render->mlx_ptrs.win_ptr, render->mlx_ptrs.veil.ptr, 0, 0);
	put.pos = ft_put_header(put, render->options, render->last_render_time);
	if (ft_option_isset(render->options, O_SHOW_OPTIONS))
		ft_menu_put_options(put, render->options);
	else
		ft_put_main_page(put, render);
	ft_put_footer(put, render->options, render->mlx_ptrs.img.size.y);
}
