/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:13:48 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 12:59:56 by sqiu             ###   ########.fr       */
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

// standard increments
# define INC_LOW 0.1f
# define INC_MID 0.5f
# define INC_HIGH 1.0f

// menu colours
# define DARK_MODERATE_CYAN 0x3391A1
# define VERY_LIGHT_GRAY	0xEBEBEB

// menu parameters
# define MENU_WIDTH 200
# define MENU_OPACITY 100
# define MENU_BACK DARK_MODERATE_CYAN
# define MENU_FONT VERY_LIGHT_GRAY

#endif
