/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:13:48 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 11:37:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CONFIG_H
# define MINIRT_CONFIG_H

/* ===== MACROS ===== */

// init buffer size for file import
# define BUF_SIZE 4096

// maximum for each entity
# define AMBIENT_MAX 1
# define CAMERA_MAX 1
# define LIGHT_MAX 1
# define SPHERE_MAX 100
# define PLANE_MAX 100
# define CYLINDER_MAX 100

// allowed interval of parsed floats
# define FLOAT_MIN -1000.0
# define FLOAT_MAX 1000.0

// standard window size
# define WIN_SIZE_X 800
# define WIN_SIZE_Y 600

// standard movement speed
# define MV_UNIT 0.5f

// menu parameters
# define MENU_WIDTH 200
# define REGULAR "-schumacher-*-medium-r-normal-*-*-160-*-*-*-*-*-*"
# define BOLD "-schumacher-*-bold-r-normal-*-*-160-*-*-*-*-*-*"
# define MENU_OPACITY 100
# define MENU_BACK 0x000000
# define MENU_FONT 0xFFFFFF

#endif