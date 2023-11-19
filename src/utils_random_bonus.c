/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:20:40 by u413q             #+#    #+#             */
/*   Updated: 2023/11/19 20:29:09 by u413q            ###   ########.fr       */
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
