/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:23:38 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/12 14:10:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "ft_char.h"

#define MAX_DIGITS 15

static size_t	ft_conv_nums(const char *str, long *result)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		*result = *result * 10.0 + (str[i] - '0');
		i++;
	}
	return (i);
}

double	ft_strtod(const char *str, size_t *offset)
{
	int		sign;
	int		i_integer;
	int		i_fract;
	long	result;

	sign = 1;
	if (*str == '-' && str++)
		sign = -1;
	result = 0;
	i_fract = 0;
	i_integer = ft_conv_nums(str, &result);
	if (str[i_integer] == '.')
		i_fract = ft_conv_nums(str + i_integer + 1, &result);
	if (!i_integer || i_integer + i_fract > MAX_DIGITS
		|| (i_integer && str[i_integer] == '.' && !i_fract))
	{
		*offset = 0;
		return (0.0);
	}
	*offset = i_integer + i_fract;
	if (str[i_integer] == '.')
		(*offset)++;
	if (sign == -1)
		(*offset)++;
	return (result / pow(10, i_fract) * sign);
}
