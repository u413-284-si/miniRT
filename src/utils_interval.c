/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_interval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:42 by u413q             #+#    #+#             */
/*   Updated: 2024/01/19 00:20:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS
# include "utils_bonus.h"
#else
# include "utils.h"
#endif

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
