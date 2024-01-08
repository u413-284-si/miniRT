/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:34:39 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 14:40:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_menu_init(t_menu *menu, uint8_t alpha, uint32_t colour,
			uint32_t font_col)
{
	menu->inv_alpha = 255 - alpha;
	menu->rb = (colour & 0xFF00FF) * alpha;
	menu->g = (colour & 0x00FF00) * alpha;
	menu->font_col = font_col;
}
