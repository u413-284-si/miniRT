/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:44:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 16:11:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

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
typedef enum e_err
{
	SUCCESS,
	ERROR
}	t_err;

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

#endif
