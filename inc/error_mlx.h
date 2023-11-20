/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:06:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 15:01:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MLX_H
# define ERROR_MLX_H

/* ====== LIBRARIES ====== */

// System libs
#include <mlx.h>

// Home-grown libs
# include "error_type.h"
# include "error_msg.h"

/* ====== FUNCTIONS ====== */

t_err	ft_err_mlx_init(void **ptr);
t_err	ft_err_mlx_new_window(void **ptr, void *mlx_ptr, int size[2], char *title);
t_err	ft_err_mlx_new_image(void **ptr, void *mlx_ptr, int size[2]);

#endif