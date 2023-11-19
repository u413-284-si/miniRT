/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:20:40 by u413q             #+#    #+#             */
/*   Updated: 2023/11/19 21:24:11 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

float	ft_random_float(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

float	ft_random_float_in(float min, float max)
{
	return (min + (max - min) * ft_random_float());
}

float	ft_clamp(float x, t_interval interval)
{
	if (x < interval.min)
		return (interval.min);
	else if (x > interval.max)
		return (interval.max);
	return (x);
}
