/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:10:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 17:20:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_OPTIONS_BONUS_H
# define RENDER_OPTIONS_BONUS_H

/* ====== TYPEDEF ====== */

typedef enum e_options
{
	O_MODE_SCENE = 1,
	O_MODE_LIGHT = 2,
	O_MODE_CAM = 3,
	O_SCENE_CHANGED = 4,
	O_SHOW_MENU = 5,
	O_SHOW_CTRL = 6,
	O_MANIP_LOW = 7,
	O_MANIP_MID = 8,
	O_MANIP_HIGH = 9,
	O_SHOW_FPS = 10,
	O_IS_THREADED = 11
}	t_options;

#endif
