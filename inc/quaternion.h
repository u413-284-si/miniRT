/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:55:14 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/27 10:14:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

/* ====== LIBRARIES ====== */

# include <math.h>

/* ====== TYPEDEFS ====== */

typedef struct s_quat {
	float x;
	float y;
	float z;
	float w;
}	t_quat;

/* ====== FUNCTIONS ====== */

float	ft_quat_len(t_quat quat);
t_quat	ft_quat_norm(t_quat quat);
t_quat	ft_quat_conjugate(t_quat quat);
t_quat	ft_quat_mult(t_quat a, t_quat b);

#endif