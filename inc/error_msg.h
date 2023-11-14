/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:23:15 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/14 17:12:42 by gwolf            ###   ########.fr       */
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

/* ====== TYPEDEFS ====== */

/**
 * @brief Gives return of function explicit meaning with SUCCESS or ERROR.
 *
 */
typedef enum e_err {
	SUCCESS,
	ERROR
}	t_err;

/* ====== FUNCTIONS ====== */

/**
 * @brief Print error message.
 *
 * Prints "Error\n" and then
 * - prints the passed error msg with perror().
 * - if errno = 0 just the msg gets printed with ft_putendl_fd()
 * @param msg			Error message to print.
 * @param save_errno	Errno at the time of calling the function.
 */
void	ft_perror(char *msg, int save_errno);

#endif