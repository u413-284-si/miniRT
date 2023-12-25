/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 07:45:12 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 20:19:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

/* ====== TYPEDEFS ====== */

/**
 * @brief 2D vector with float.
 *
 * @param x		X coordinate.
 * @param y		Y coordinate.
 */
typedef struct s_vec2f
{
	float		x;
	float		y;
}	t_vec2f;

/**
 * @brief 2D vector with int.
 *
 * @param x		X coordinate.
 * @param y		Y coordinate.
 */
typedef struct s_vec2i
{
	int			x;
	int			y;
}	t_vec2i;

#endif