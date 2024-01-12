/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:59:14 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/09 17:42:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

/* ====== LIBRARIES ====== */

# include "utils.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief 4x4 matrix of floats.
 *
 * Typedef'd to make it possible to return a matrix from a function.
 * Column major -> matrix[column][row]
 * @param mat	4x4 matrix
 */
typedef struct s_mat4
{
	float	mat[4][4];
}	t_mat4;
/* ====== FUNCTIONS ====== */

// mat4.c

/**
 * @brief Returns a 4x4 identity matrix.
 *
 * @return t_mat4 4x4 identity matrix.
 */
t_mat4	ft_mat4_set_identity(void);

/**
 * @brief Copies a 4x4 matrix.
 *
 * @param src 		Source matrix.
 * @return t_mat4	Copy of source matrix.
 */
t_mat4	ft_mat4_copy(const t_mat4 src);

/**
 * @brief Multiplies two 4x4 matrices.
 *
 * @param left		Left matrix.
 * @param right		Right matrix.
 * @return t_mat4	Product of left and right matrix.
 */
t_mat4	ft_mat4_mult_mat4(const t_mat4 left, const t_mat4 right);

// mat4_rotation.c

/**
 * @brief Creates a 4x4 transformation matrix for x-axis rotation.
 *
 * @param roll		Roll angle in degrees.
 * @return t_mat4	4x4 rotation matrix.
 */
t_mat4	ft_mat4_create_rotate_x(float roll);

/**
 * @brief Creates a 4x4 transformation matrix for y-axis rotation.
 *
 * @param pitch		Pitch angle in degrees.
 * @return t_mat4	4x4 rotation matrix.
 */
t_mat4	ft_mat4_create_rotate_y(float pitch);

/**
 * @brief Creates a 4x4 transformation matrix for z-axis rotation.
 *
 * @param yaw		Yaw angle in degrees.
 * @return t_mat4	4x4 rotation matrix.
 */
t_mat4	ft_mat4_create_rotate_z(float yaw);

#endif
