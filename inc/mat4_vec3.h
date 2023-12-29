/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vec3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:00:57 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/28 13:02:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_VEC3_H
# define MAT4_VEC3_H
/* ====== LIBRARIES ====== */
// Home-grown libs
# include "vec3_bonus.h"
# include "mat4.h"
/* ====== FUNCTIONS ====== */

// mat4_vec3_rotate.c

/**
 * @brief Multiplies a 4x4 matrix with a 3D vector.
 *
 * @param mat 		4x4 matrix.
 * @param vec		3D vector.
 * @return t_vec3	Product of matrix and vector.
 */
t_vec3	ft_vec3_mult_mat4(const t_mat4 mat, const t_vec3 vec);

/**
 * @brief Rotates a 3D vector around the x-axis.
 *
 * Constructs x-rotation matrix and multiplies it with the vector.
 * The vector gets normalized after the rotation.
 * @param vec		3D vector.
 * @param roll		Rotation angle in degrees.
 * @return t_vec3	Rotated, normalized vector.
 */
t_vec3	ft_vec3_rotate_x(const t_vec3 vec, float roll);

/**
 * @brief Rotates a 3D vector around the y-axis.
 *
 * Constructs y-rotation matrix and multiplies it with the vector.
 * The vector gets normalized after the rotation.
 * @param vec		3D vector.
 * @param pitch		Rotation angle in degrees.
 * @return t_vec3	Rotated, normalized vector.
 */
t_vec3	ft_vec3_rotate_y(const t_vec3 vec, float pitch);

/**
 * @brief Rotates a 3D vector around the z-axis.
 *
 * Constructs z-rotation matrix and multiplies it with the vector.
 * The vector gets normalized after the rotation.
 * @param vec		3D vector.
 * @param yaw		Rotation angle in degrees.
 * @return t_vec3	Rotated, normalized vector.
 */
t_vec3	ft_vec3_rotate_z(const t_vec3 vec, float yaw);

#endif
