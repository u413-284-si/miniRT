/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_config_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:13:48 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 16:31:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CONFIG_BONUS_H
# define MINIRT_CONFIG_BONUS_H

/* ===== MACROS ===== */

// init buffer size for file import
# define BUF_SIZE 4096

// maximum for each entity
# define AMBIENT_MAX 1
# define CAMERA_MAX 1
# define LIGHT_MAX 100
# define SPHERE_MAX 100
# define PLANE_MAX 100
# define CYLINDER_MAX 100

// allowed interval of parsed floats
# define FLOAT_MIN -10000.0
# define FLOAT_MAX 10000.0

// standard window size
# define WIN_SIZE_X 800
# define WIN_SIZE_Y 600

// sample size
# define SAMPLE_SIZE 5

#endif
