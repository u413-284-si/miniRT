/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_field.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:06:03 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 13:40:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_FIELD_H
# define BIT_FIELD_H

/* ====== LIBRARIES ====== */

# include <stdint.h>
# include <stdbool.h>

/* ====== FUNCTIONS ====== */

/**
 * @brief Checks if bit is set in the bit field
 *
 * @param bit_field	Bit field to check
 * @param bit		Bit to check
 * @return true		Bit is set
 * @return false	Bit is not set
 */
bool	ft_bit_is_set(uint8_t bit_field, uint8_t bit);

/**
 * @brief Sets bit in bit field
 *
 * @param bit_field	Bit field where bit to set
 * @param bit		Bit to set
 */
void	ft_bit_set(uint8_t *bit_field, uint8_t bit);

/**
 * @brief Clears bit in bit field
 *
 * @param bit_field	Bit field where bit to clear
 * @param bit		Bit to clear
 */
void	ft_bit_clear(uint8_t *bit_field, uint8_t bit);

/**
 * @brief Toggles bit in bit field
 *
 * @param bit_field	Bit field where bit to toggle
 * @param bit		Bit to toggle
 */
void	ft_bit_toggle(uint8_t *bit_field, uint8_t bit);

#endif
