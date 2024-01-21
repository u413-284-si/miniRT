/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:39:56 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 00:15:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put_bonus.h"

static void	ft_menu_put_options_ctrl(t_putinfo put)
{
	put.pos = ft_put_str_and_advance(put, "General controls");
	put.pos.y += Y_HALF_LINE;
	put.pos = ft_put_str_and_advance(put, "Ctrl:  Switch mode");
	put.pos = ft_put_str_and_advance(put, "Shift: Show info");
	put.pos.y += Y_HALF_LINE;
	put.pos = ft_put_str_and_advance(put, "U: Change increment");
	put.pos = ft_put_str_and_advance(put, "I: Toggle menu");
	put.pos = ft_put_str_and_advance(put, "O: Show options");
	put.pos = ft_put_str_and_advance(put, "P: Print scene");
	put.pos = ft_put_str_and_advance(put, "J: Toggle threads");
	put.pos = ft_put_str_and_advance(put, "K: Toggle");
	put.pos = ft_put_str_and_advance(put, "      anti-aliasing");
	put.pos = ft_put_str_and_advance(put, "L: Toggle time unit");
}

void	ft_menu_put_options(t_putinfo put, uint32_t options)
{
	if (ft_option_isset(options, O_SHOW_CTRL))
		return (ft_menu_put_options_ctrl(put));
	if (ft_option_isset(options, O_IS_THREADED))
	{
		put.pos = ft_put_str_and_advance(put, "Threading: ON");
		put.pos = ft_put_single_float_value("Threads", put, NUM_THREADS);
	}
	else
		put.pos = ft_put_str_and_advance(put, "Threading: OFF");
	put.pos.y += Y_NEXT_LINE;
	if (ft_option_isset(options, O_IS_ANTI_ALIAS))
	{
		put.pos = ft_put_str_and_advance(put, "Anti-Aliasing: ON");
		put.pos = ft_put_single_float_value("Samples", put, SAMPLE_SIZE);
	}
	else
		put.pos = ft_put_str_and_advance(put, "Anti-Aliasing: OFF");
}
