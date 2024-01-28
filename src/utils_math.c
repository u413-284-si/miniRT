/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:48:18 by u413q             #+#    #+#             */
/*   Updated: 2024/01/28 15:55:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.h"

float	ft_degree_to_radian(float degrees)
{
	return (degrees * RAD);
}

float	ft_radian_to_degree(float radians)
{
	return (radians * DEG);
}

bool	ft_solve(t_equation *eq)
{
	float	discriminant;

	if (eq->a == 0.0 && eq->b != 0.0)
	{
		eq->d1 = -eq->c / eq->b;
		return (true);
	}
	discriminant = eq->b * eq->b - 4.0 * eq->a * eq->c;
	if (discriminant < 0)
		return (false);
	eq->d1 = (-eq->b - sqrt(discriminant)) / (2.0 * eq->a);
	eq->d2 = (-eq->b + sqrt(discriminant)) / (2.0 * eq->a);
	return (true);
}

bool	ft_nearly_equal_flt(float one, float two)
{
	if (fabs(one - two) < EPSILON)
		return (true);
	return (false);
}
