/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:34:39 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/30 16:39:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

t_menu	ft_init_menu(uint8_t alpha, uint32_t colour, uint32_t font_col)
{
	t_menu	menu;

	menu.inv_alpha = 255 - alpha;
	menu.rb = (colour & 0xFF00FF) * alpha;
	menu.g = (colour & 0x00FF00) * alpha;
	menu.font_col = font_col;
	return (menu);
}
