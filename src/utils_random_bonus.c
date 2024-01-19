/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:20:40 by u413q             #+#    #+#             */
/*   Updated: 2024/01/19 12:38:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

float	ft_random_float(void)
{
	srand(time(0));
	return (rand() / (RAND_MAX + 1.0));
}

float	ft_random_float_within(float min, float max)
{
	return (min + (max - min) * ft_random_float());
}
