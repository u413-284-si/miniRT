/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:48:07 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 11:59:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

/* ====== TYPEDEFS ====== */

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

/* ====== FUNCTIONS ====== */

/**
 * @brief Creates a new vector with four floats.
 *
 * @param x
 * @param y
 * @param z
 * @param w
 * @return t_vec4
 */
t_vec4	ft_vec4_create(float x, float y, float z, float w);

#endif
