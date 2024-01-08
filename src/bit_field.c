/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:05:49 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 13:25:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_field.h"

bool	ft_bit_is_set(uint8_t bit_field, uint8_t bit)
{
	return (bit_field & bit);
}

uint8_t	ft_bit_set(uint8_t bit_field, uint8_t bit)
{
	bit_field |= bit;
	return (bit_field);
}

uint8_t	ft_bit_clear(uint8_t bit_field, uint8_t bit)
{
	bit_field &= ~bit;
	return (bit_field);
}

uint8_t	ft_bit_toggle(uint8_t bit_field, uint8_t bit)
{
	bit_field ^= bit;
	return (bit_field);
}
