/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:00:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 15:18:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

/* ====== LIBRARIES ====== */

# include <stdlib.h>
# include <mlx.h>

/* ====== FUNCTIONS ====== */

/**
 * @brief Frees a NULL-terminated char ** array.
 *
 * Loops through array, freeing every char *.
 * At the end free the char ** itself.
 * @param array Array to free.
 */
void	ft_free_char_arr(char **array);

void	ft_free_mlx(void *mlx_ptr, void *win_ptr, void *img_ptr);

#endif