/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:20:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 16:23:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_BONUS_H
# define MANIP_BONUS_H

/* ====== LIBRARIES ====== */

# include "manip.h"
# include "render_struct_bonus.h"

// render_keyhook_options_bonus.c

/**
 * @brief Handles bonus option keys.
 *
 * 'O': Show options.
 * 'P': Start printing.
 * 'J': Toggle threading.
 * 'K': Toggle anti-aliasing.
 * 'L': Toggle time unit.
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 */
void		ft_change_options_bonus(int key, t_render *render);

// render_keyhook_hittable_bonus.c

/**
 * @brief Manipulates the active cone.
 *
 * @param key	Keycode of the pressed key.
 * @param co	Pointer to cone struct.
 * @param inc	Increment value.
 */
void		ft_manip_cone(int key, t_cone *co, float inc);

#endif
