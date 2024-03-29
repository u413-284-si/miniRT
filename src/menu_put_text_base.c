/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 12:05:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

static t_vec2i	ft_put_header(t_putinfo put, uint32_t options)
{
	put.pos = ft_put_mode(put, options);
	if (!ft_option_isset(options, O_SHOW_CTRL))
		put.pos = ft_put_inc(put, options);
	put.pos.x -= 15;
	put.pos = ft_put_str_and_advance(put, "------------------------");
	put.pos.x += 15;
	put.pos.y += Y_HALF_LINE;
	return (put.pos);
}

static t_vec2i	ft_put_footer(t_putinfo put, bool show_ctrl, int img_height)
{
	if (show_ctrl == true)
		put.pos.y = img_height - Y_MENU_BOTTOM_BIG;
	else
		put.pos.y = img_height - Y_MENU_BOTTOM_SMALL;
	put.pos.x -= 15;
	put.pos = ft_put_str_and_advance(put, "-------General----------");
	put.pos.x += 15;
	if (show_ctrl == true)
	{
		put.pos = ft_put_str_and_advance(put, "Ctrl:  Switch mode");
		put.pos = ft_put_str_and_advance(put, "U:     Change inc");
		put.pos = ft_put_str_and_advance(put, "I:     Toggle menu");
		put.pos = ft_put_str_and_advance(put, "Shift: Show info");
	}
	else
		put.pos = ft_put_str_and_advance(put, "Shift: Show controls");
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
	put.pos = ft_put_header(put, render->options);
	ft_put_main_page(put, render);
	ft_put_footer(put, ft_option_isset(render->options, O_SHOW_CTRL),
		render->mlx_ptrs.img.size.y);
}
