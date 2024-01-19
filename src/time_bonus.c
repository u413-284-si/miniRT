/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:22:22 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 10:27:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_bonus.h"

uint64_t	ft_get_time_ms(void)
{
	static struct timespec	spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);
	return ((spec.tv_sec * 1000) + (spec.tv_nsec / 1e6));
}
