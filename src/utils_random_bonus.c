/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:20:40 by u413q             #+#    #+#             */
/*   Updated: 2024/01/20 14:30:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

float	ft_random_float(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

float	ft_random_float_within(float min, float max)
{
	return (min + (max - min) * ft_random_float());
}
