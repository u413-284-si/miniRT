/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2024/01/12 17:54:36 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

/* ====== LIBRARIES ====== */

# include "ray.h"
# include "utils.h"
# include "miniRT_config.h"
# include "structs_bonus.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

/**
 * @brief Sets values of camera parameters
 *
 * @param cam 	Struct containing camera parameters
 */
void	ft_initiate_camera(t_cam *cam);

/**
 * @brief Sets values of viewport parameters
 *
 * @param vp		Struct containing viewport parameters
 * @param cam 		Struct containing camera parameters
 * @param size_x	Width of image.
 * @param size_y	Height of image.
 */
void	ft_initiate_viewport(t_viewport *vp, t_cam cam, int size_x, int size_y);

#endif
