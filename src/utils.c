/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:48:18 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 11:38:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	ft_degree_to_radian(float degrees)
{
	return (degrees * RAD);
}

float	ft_radian_to_degree(float radians)
{
	return (radians * RAD_TO_DEG);
}

bool	ft_contains(float x, t_interval interval)
{
	return (interval.min <= x && interval.max >= x);
}

bool	ft_surrounds(float x, t_interval interval)
{
	return (interval.min < x && interval.max > x);
}

float	ft_solve(t_equation *eq)
{
	float	discriminant;

	if (eq->a == 0.0 && eq->b != 0.0)
	{
		eq->d1 = -eq->c / eq->b;
		return (0);
	}
	discriminant = pow(eq->b, 2) - 4.0 * eq->a * eq->c;
	if (discriminant < 0)
		return (-1);
	eq->d1 = (-eq->b - sqrt(discriminant)) / (2.0 * eq->a);
	eq->d2 = (-eq->b + sqrt(discriminant)) / (2.0 * eq->a);
	return (discriminant);
}

bool	ft_nearly_equal_flt(float one, float two)
{
	if (fabs(one - two) < EPSILON)
		return (true);
	return (false);
}
