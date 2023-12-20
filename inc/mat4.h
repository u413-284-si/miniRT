/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:53:31 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/20 11:44:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

/* ====== LIBRARIES ====== */
# include "utils.h"

/* ====== TYPEDEFS ====== */

typedef struct s_mat4
{
	float	mat[4][4];
}	t_mat4;

/* ====== FUNCTIONS ====== */

// mat4.c
t_mat4	ft_mat4_set_identity(void);
t_mat4	ft_mat4_copy(const t_mat4 src);
t_mat4	ft_mat4_mult_mat4(const t_mat4 left, const t_mat4 right);

// mat4_rotation.c
t_mat4	ft_mat4_create_rotate_x(float roll);
t_mat4	ft_mat4_create_rotate_y(float pitch);
t_mat4	ft_mat4_create_rotate_z(float yaw);

#endif
