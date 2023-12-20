/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vec3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:33:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/20 11:43:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_VEC3_H
# define MAT4_VEC3_H

/* ====== LIBRARIES ====== */

// Home-grown libs
# include "vec3.h"
# include "mat4.h"

/* ====== FUNCTIONS ====== */

// mat4_vec3_rotate.c
t_vec3	ft_vec3_mult_mat4(const t_mat4 mat, const t_vec3 vec);
t_vec3	ft_vec3_rotate_x(const t_vec3 vec, float roll);
t_vec3	ft_vec3_rotate_y(const t_vec3 vec, float pitch);
t_vec3	ft_vec3_rotate_z(const t_vec3 vec, float yaw);

#endif