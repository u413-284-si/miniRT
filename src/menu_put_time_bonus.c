/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_time_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:46:17 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/13 10:57:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_time(t_putinfo put, uint64_t last_render_time, bool show_fps)
{
	const float	fps = 1000.0 / (last_render_time);

	if (show_fps == true)
	{
		ft_put_str(put, "FPS: ");
		put.pos.x += 30;
		ft_put_float(put, (t_numinfo){.numf = fps, .pad = 2, .prec = 2});
		put.pos.x -= 30;
		put.pos.y += Y_NEXT_LINE;
		return (put.pos);
	}
	ft_put_str(put, "Time (ms): ");
	put.pos.x += 90;
	ft_put_int(put, (t_numinfo){.numi = last_render_time, .pad = 4, .prec = 0});
	put.pos.x -= 90;
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}
