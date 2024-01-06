/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:57:42 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 19:08:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MENU_H
# define RENDER_MENU_H

/* ====== LIBRARIES ====== */

# include <stdint.h>

# include "miniRT_config.h"

/* ====== MACROS ====== */

typedef enum e_pages
{
	PAGE_SCENE,
	PAGE_LIGHT,
	PAGE_CAM,
	PAGE_SCENE_CTRL,
	PAGE_LIGHT_CTRL,
	PAGE_CAM_CTRL,
	PAGE_SCENE_LST,
	PAGE_LIGHT_LST
}	t_pages;

typedef struct s_menu
{
	uint8_t		inv_alpha;
	uint32_t	rb;
	uint32_t	g;
	uint32_t	font_col;
	t_pages		cur_page;
}	t_menu;

/* ====== FUNCTIONS ====== */

void	ft_menu_init(t_menu *menu, uint8_t alpha, uint32_t colour,
			uint32_t font_col);

#endif
