/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:00:19 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/12 22:52:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

/* ====== LIBRARIES ====== */

# include <stdlib.h>
# include <mlx.h>

// Home-grown libs
# if IS_BONUS == 1
#  include "entities_bonus.h"
# else
#  include "entities.h"
# endif

/* ====== FUNCTIONS ====== */

/**
 * @brief Frees a NULL-terminated char ** array.
 *
 * Loops through array, freeing every char *.
 * At the end free the char ** itself.
 * @param array Array to free.
 */
void	ft_free_char_arr(char **array);

/**
 * @brief Frees ressources allocated for mlx.
 *
 * @param mlx_ptr	Pointer to mlx.
 * @param win_ptr	Pointer to mlx_window.
 * @param img_ptr	Pointer to mlx_image.
 * @param menu_ptr	Pointer to mlx_image.
 */
void	ft_free_mlx(void *mlx_ptr, void *win_ptr, void *img_ptr,
			void *menu_ptr);

/**
 * @brief Frees memory allocated for a scene.
 *
 * @param scene	Pointer to scene.
 */
void	ft_free_scene(t_entities *scene);

#endif
