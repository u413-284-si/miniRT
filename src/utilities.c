/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:48:18 by u413q             #+#    #+#             */
/*   Updated: 2023/10/29 17:56:09 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

float	ft_degree_to_radian(float degrees)
{
	return (degrees * M_PI / 180.0);
}

bool	ft_contains(float x, t_interval interval)
{
	return (interval.min <= x && interval.max >= x);
}

bool	ft_surrounds(float x, t_interval interval)
{
	return (interval.min < x && interval.max > x);
}
