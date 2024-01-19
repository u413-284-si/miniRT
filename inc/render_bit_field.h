/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bit_field.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:06:03 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 10:10:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BIT_FIELD_H
# define RENDER_BIT_FIELD_H

/* ====== LIBRARIES ====== */

# include <stdint.h>
# include <stdbool.h>

# if IS_BONUS
#  include "render_options_bonus.h"
# else
#  include "render_options.h"
# endif

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
