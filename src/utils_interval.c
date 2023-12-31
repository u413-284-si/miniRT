/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_interval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:42 by u413q             #+#    #+#             */
/*   Updated: 2023/12/25 20:34:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_interval(t_interval *interval)
{
	interval->max = INFINITY;
	interval->min = 0;
}

bool	ft_contains(float x, t_interval interval)
{
	return (interval.min <= x && interval.max >= x);
}

bool	ft_surrounds(float x, t_interval interval)
{
	return (interval.min < x && interval.max > x);
}

float	ft_clamp(float x, t_interval interval)
{
	if (x < interval.min)
		return (interval.min);
	else if (x > interval.max)
		return (interval.max);
	return (x);
}