/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:51:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/14 07:49:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOD_H
# define FT_STRTOD_H

/* ====== LIBRARIES ====== */

# include <stdio.h>
# include <math.h>

# include "ft_char.h"

/* ===== MACROS ===== */

# define MAX_DIGITS 15

/* ====== FUNCTIONS ====== */

/**
 * @brief Converts a String to a double.
 *
 * Simple implementation: handles only numbers with upto 15 digits excluding
 * an optional radix point. 15 digits can be stored in long without overflow.
 *
 * Does NOT ignore spaces at the beginning.
 * Does allow 1 negative sign (-).
 * Radix point is the dot char (.) and is optional (can convert ints like 123).
 *
 * Convert all digits in string to number, ignoring radix (12.345 => 12345).
 * Divide by 10 to the power of fractional digits with pow().
 *
 * There has to be at least 1 digit before radix.
 * If there is radix there has to be at least 1 digit following.
 * The number of digits shall not be more than 15.
 * If the number is not convertible returns 0.0 and sets offset to 0.
 *
 * @param str		The string to convert.
 * @param offset	Offset from start until end of number, incl sign and radix.
 * @return double	Converted value.
 */
double	ft_strtod(const char *str, size_t *offset);

#endif