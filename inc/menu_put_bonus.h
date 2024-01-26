/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:51:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 12:20:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_PUT_BONUS_H
# define MENU_PUT_BONUS_H

/* ====== LIBRARIES ====== */

# include "menu_put.h"

/* ====== FUNCTIONS ====== */

/**
 * @brief Puts a timestamp on the screen.
 *
 * @param put 				Putinfo struct
 * @param last_render_time	Last render time in ms
 * @param show_fps			Whether to convert to FPS
 * @return t_vec2i			Position after the timestamp
 */
t_vec2i	ft_put_time(t_putinfo put, uint64_t last_render_time, bool show_fps);

/**
 * @brief Puts the options of renderer on the screen.
 *
 * @param put 		Putinfo struct
 * @param options	Options bit field.
 */
void	ft_menu_put_options(t_putinfo put, uint32_t options);

/**
  * @brief Puts cone info on the screen.
 *
 * Writes the centre, axis, diameter, height and colour of the cone.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param co		Cone to be put on screen.
 */
void	ft_put_co(t_putinfo put, t_cone co);

#endif
