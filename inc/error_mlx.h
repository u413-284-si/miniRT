/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:06:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/12 22:55:19 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MLX_H
# define ERROR_MLX_H

/* ====== LIBRARIES ====== */

// System libs
# include <mlx.h>

// Home-grown libs
# include "error_type.h"
# include "error_msg.h"
# include "vec2.h"

/* ====== FUNCTIONS ====== */

/**
 * @brief Wrapper function for mlx_init() to print errno.
 *
 * @param ptr		Pointer to mlx_ptr.
 * @return t_err	SUCCESS, ERROR
 */
t_err	ft_err_mlx_init(void **ptr);

/**
 * @brief Wrapper function for mlx_new_window() to print errno.
 *
 * @param ptr		Pointer to win_ptr.
 * @param mlx_ptr	Pointer to mlx_ptr.
 * @param size		Window size as int array.
 * @param title		Window title.
 * @return t_err	SUCCESS, ERROR.
 */
t_err	ft_err_mlx_new_window(void **ptr, void *mlx_ptr, t_vec2i size, char *title);

/**
 * @brief Wrapper function for mlx_new_image() to print errno.
 *
 * @param ptr		Pointer to img_ptr.
 * @param mlx_ptr	Pointer to mlx_ptr.
 * @param size		Image size as int array.
 * @return t_err	SUCCESS, ERROR.
 */
t_err	ft_err_mlx_new_image(void **ptr, void *mlx_ptr, t_vec2i size);

#endif
