/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:44:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 14:36:41 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdio.h>
# include <errno.h>

// Home-grown libs
# include "ft_fd.h"

# if IS_BONUS
#  include "entities_bonus.h"
# else
#  include "entities.h"
# endif

/* ====== FUNCTIONS ====== */

// error_msg_generic.c

/**
 * @brief Print generic error message.
 *
 * Prints "Error\n" and then
 * - prints the passed error msg with perror().
 * - if errno = 0 just the msg gets printed with ft_putendl_fd()
 * @param msg			Error message to print.
 * @param save_errno	Errno at the time of calling the function.
 */
void	ft_perror(char *msg, int save_errno);

/**
 * @brief Print error message with a number
 *
 * The number gets enclosed with <>. *
 * @param msg		Error message to print.
 * @param number	Number to print.
 */
void	ft_perror_number(char *msg, int number);

#endif
