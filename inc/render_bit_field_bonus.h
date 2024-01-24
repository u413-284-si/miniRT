/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bit_field_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:06:03 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 10:31:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BIT_FIELD_BONUS_H
# define RENDER_BIT_FIELD_BONUS_H

/* ====== LIBRARIES ====== */

# include <stdint.h>
# include <stdbool.h>

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
	O_IS_THREADED = 11,
	O_IS_ANTI_ALIAS = 12,
	O_SHOW_OPTIONS = 13,
	O_IS_PRINTING = 14
}	t_options;

/* ====== FUNCTIONS ====== */

/**
 * @brief Checks if bit is set in the bit field
 *
 * @param bit_field	Bit field to check
 * @param bit		Bit to check
 * @return true		Bit is set
 * @return false	Bit is not set
 */
bool	ft_option_isset(uint32_t bit_field, t_options option);

/**
 * @brief Sets bit in bit field
 *
 * @param bit_field	Bit field where bit to set
 * @param bit		Bit to set
 */
void	ft_option_set(uint32_t *bit_field, t_options option);

/**
 * @brief Clears bit in bit field
 *
 * @param bit_field	Bit field where bit to clear
 * @param bit		Bit to clear
 */
void	ft_option_clear(uint32_t *bit_field, t_options option);

/**
 * @brief Toggles bit in bit field
 *
 * @param bit_field	Bit field where bit to toggle
 * @param bit		Bit to toggle
 */
void	ft_option_toggle(uint32_t *bit_field, t_options option);

#endif
