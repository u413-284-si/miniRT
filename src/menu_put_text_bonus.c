/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_text_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/12 19:30:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put_bonus.h"

static t_vec2i	ft_put_header(t_putinfo put, uint32_t options,
		uint64_t last_render_time)
{
	put.pos = ft_put_mode(put, options);
	put.pos = ft_put_time(put, last_render_time,
			ft_option_isset(options, O_SHOW_FPS));
	return (put.pos);
}

static t_vec2i ft_put_footer(t_putinfo put, bool show_ctrl)
{
	if (show_ctrl == true)
		put.pos = (t_vec2i){X_MENU_OFFSET, Y_MENU_INFO_POS};
	else
		put.pos = (t_vec2i){X_MENU_OFFSET, 550};
	put.pos.x -= 15;
	ft_put_str(put, "-------General----------");
	put.pos.x += 15;
	put.pos.y += Y_NEXT_LINE;
	if (show_ctrl == true)
	{
		ft_put_str(put, "Ctrl:  Switch mode");
		put.pos.y += Y_NEXT_LINE;
		ft_put_str(put, "I:     Toggle menu");
		put.pos.y += Y_NEXT_LINE;
		ft_put_str(put, "O:     Toggle FPS");
		put.pos.y += Y_NEXT_LINE;
		ft_put_str(put, "P:     Print scene");
		put.pos.y += Y_NEXT_LINE;
		ft_put_str(put, "Shift: Show info");
	}
	else
		ft_put_str(put, "Shift: Show controls");
	put.pos.y += Y_NEXT_LINE;
	ft_put_str(put, "ESC:   Exit");
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
	ft_put_main_page(put, render);
	ft_put_footer(put, ft_option_isset(render->options, O_SHOW_CTRL));
}
