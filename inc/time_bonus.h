/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:22:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/15 22:21:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_BONUS_H
# define TIME_BONUS_H

/* ====== LIBRARIES ====== */

# include <stdint.h>
# include <unistd.h>
# include <time.h>

/* ====== FUNCTIONS ====== */

/**
 * @brief Returns the current time in milliseconds.
 *
 * Uses clock_gettime() for high precision.
 * @return uint64_t Timestamp in milliseconds.
 */
uint64_t	ft_get_time_ms(void);

#endif
