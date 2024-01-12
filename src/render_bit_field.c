/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bit_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:05:49 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/12 19:05:44 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bit_field.h"

bool	ft_option_isset(uint32_t bit_field, t_options option)
{
	const uint32_t	bit = 1 << option;

	return (bit_field & bit);
}

void	ft_option_set(uint32_t *bit_field, t_options option)
{
	const uint32_t	bit = 1 << option;

	*bit_field |= bit;
}

void	ft_option_clear(uint32_t *bit_field, t_options option)
{
	const uint32_t	bit = 1 << option;

	*bit_field &= ~bit;
}

void	ft_option_toggle(uint32_t *bit_field, t_options option)
{
	const uint32_t	bit = 1 << option;

	*bit_field ^= bit;
}
