/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:31:38 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/09 16:30:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_OPTIONS_H
# define RENDER_OPTIONS_H

/* ====== LIBRARIES ====== */

# include "bit_field.h"

/* ====== MACROS ====== */

# define O_CLEAR_ALL		0x00	// 00000000
# define O_MODE_SCENE		0x01	// 00000001
# define O_MODE_LIGHT		0x02	// 00000010
# define O_MODE_CAM			0x04	// 00000100
# define O_SCENE_CHANGED	0x08	// 00001000
# define O_SHOW_MENU		0x10	// 00010000
# define O_SHOW_FPS			0x20	// 00100000
# define O_SHOW_CTRL		0x40	// 01000000
# define O_MANIP_HIGH		0x80	// 10000000

#endif