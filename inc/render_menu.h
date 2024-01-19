/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:57:42 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 15:13:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MENU_H
# define RENDER_MENU_H

/* ====== LIBRARIES ====== */

# include <stdint.h>

# if IS_BONUS
#  include "miniRT_config_bonus.h"
# else
#  include "miniRT_config.h"
# endif

/* ====== MACROS ====== */

typedef struct s_menu
{
	uint8_t		inv_alpha;
	uint32_t	rb;
	uint32_t	g;
	uint32_t	font_col;
}	t_menu;

/* ====== FUNCTIONS ====== */

void	ft_menu_init(t_menu *menu, uint8_t alpha, uint32_t colour,
			uint32_t font_col);

#endif
