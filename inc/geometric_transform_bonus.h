/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_transform_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:27:18 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/29 19:07:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRIC_TRANSFORM_BONUS_H
# define GEOMETRIC_TRANSFORM_BONUS_H

/* ====== LIBRARIES ====== */

// home-grown libs
# include "vec3_bonus.h"
# include "structs_bonus.h"
# include "mat4.h"
# include "mat4_vec3.h"

/* ====== MACROS ====== */

# define FWDTRFM	true
# define BCKTRFM	false

/* ====== FUNCTIONS ====== */

/**
 * @brief 
 * 
 * @param translation 
 * @param rotation 
 * @param scale 
 * @param result
 */
void	ft_set_transform(t_vec3 translation, t_vec3 rotation, t_vec3 scale, \
	t_mat4 *result);

/**
 * @brief 
 * 
 */
void	ft_set_rotation_matrices(t_mat4 *rot_x_matrix, t_mat4 *rot_y_matrix, \
	t_mat4 *rot_z_matrix, t_vec3 rotation);

/**
 * @brief 
 * 
 * @param input 
 * @param dir_flag 
 * @return t_ray 
 */
t_ray	ft_transform_ray(t_ray input, bool dir_flag, t_mat4 fwd, t_mat4 bck);

/**
 * @brief 
 * 
 * @param input 
 * @param dir_flag 
 * @return t_vec3 
 */
t_vec3	ft_transform_vec3(t_vec3 input, bool dir_flag, t_mat4 fwd, t_mat4 bck);

#endif
