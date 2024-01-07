/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:22:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/07 14:06:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_BONUS_H
# define TIME_BONUS_H

/* ====== LIBRARIES ====== */

# include <stdint.h>
# include <unistd.h>
# include <sys/time.h>

/* ====== FUNCTIONS ====== */

uint64_t	ft_get_timeofday_ms(void);

#endif
