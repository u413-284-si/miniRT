/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:52:34 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 17:48:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RANDOM_BONUS_H
# define UTILS_RANDOM_BONUS_H

/* ====== LIBRARIES ====== */

# include <stdlib.h>

/* ====== FUNCTIONS ====== */

/**
 * @brief Return a random float
 *
 * @return float
 */
float	ft_random_float(void);

/**
 * @brief Return a random float within min and max
 *
 * @param min 		Lower bounder
 * @param max 		Upper bounder
 * @return float
 */
float	ft_random_float_within(float min, float max);

#endif
