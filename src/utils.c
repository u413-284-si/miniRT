/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:48:18 by u413q             #+#    #+#             */
/*   Updated: 2023/10/30 11:42:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	ft_degree_to_radian(float degrees)
{
	return (degrees * RAD);
}

bool	ft_contains(float x, t_interval interval)
{
	return (interval.min <= x && interval.max >= x);
}

bool	ft_surrounds(float x, t_interval interval)
{
	return (interval.min < x && interval.max > x);
}
