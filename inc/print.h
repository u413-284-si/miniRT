/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:26:06 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 19:13:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdio.h>

// Home-grown libs
# include "vec3.h"
# include "mat4.h"

# if IS_BONUS==1
#  include "colour_bonus.h"
#  include "entities_bonus.h"
#  include "camera_bonus.h"
# else
#  include "colour.h"
#  include "entities.h"
#  include "camera.h"
# endif

/* ====== FUNCTIONS ====== */

// print_structs.c

/**
 * @brief Prints variables of a vec3.
 *
 * @param vec	Vec3 to print.
 */
void	ft_print_vec3(const t_vec3 vec);

/**
 * @brief Prints variables of a mat4.
 *
 * @param mat	Mat4 to print.
 */
void	ft_print_mat4(const t_mat4 mat);

/**
 * @brief Prints variables of a colour.
 *
 * @param colour	Colour to print.
 */
void	ft_print_colour(const t_colour colour);

// print_entity.c

/**
 * @brief Prints parameters of camera struct.
 *
 * @param cam	Camera to print.
 */
void	ft_print_cam(const t_cam cam);

/**
 * @brief Prints parameters of a hittable.
 *
 * Depending on the type of hittable, the corresponding print function is called.
 * @param hittable	Hittable to print.
 */
void	ft_print_hittable(const t_hittable hittable);

/**
 * @brief Prints parameters of a sphere.
 *
 * @param sp	Sphere to print.
 */
void	ft_print_sphere(const t_sphere sp);

/**
 * @brief Prints parameters of a plane.
 *
 * @param pl	Plane to print.
 */
void	ft_print_plane(const t_plane pl);

/**
 * @brief Prints parameters of a cylinder.
 *
 * @param cy	Cylinder to print.
 */
void	ft_print_cylinder(const t_cylinder cy);

#endif
