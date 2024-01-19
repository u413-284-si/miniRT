/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:31:38 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/13 09:23:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_OPTIONS_H
# define RENDER_OPTIONS_H

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
	O_MANIP_HIGH = 9
}	t_options;

#endif
