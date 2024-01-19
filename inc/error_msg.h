/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:44:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 00:19:18 by sqiu             ###   ########.fr       */
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

// error_msg_check.c

/**
 * @brief Error message if entity count is not correct.
 *
 * @param type Entity type.
 * @param max Maximum number for entity type.
 * @param count Found number for entity type.
 * @param high Controls if count is too high or too low.
 */
void	ft_perror_count(t_type type, int max, int count, bool high);

/**
 * @brief Error message if converted number is out of range.
 *
 * @param line Start position of converted number.
 * @param offset Offset from start position.
 * @param min Minimum for number.
 * @param max Maximum for number.
 * @return false Always returns false to chain msg and false in return.
 */
bool	ft_perror_range(char *line, size_t offset, int min, int max);

/**
 * @brief Error message if conversion failed.
 *
 * @param line Line with current position, where conversion failed.
 * @param is_float Controls if converted number should have been float.
 * @return false Always returns false to chain msg and false in return.
 */
bool	ft_perror_convert(char *line, bool is_float);

/**
 * @brief Error message if wrong separator was encountered.
 *
 * @param line Line with current position, where separator was encountered.
 * @param comma Controls if separator should be ',' or ' ' and '\0'.
 * @return false Always returns false to chain msg and false in return.
 */
bool	ft_perror_separator(char *line, bool comma);

/**
 * @brief Error message if line doesn't end with space or zero terminator.
 *
 * @param line Line with current position, where wrong char was encountered.
 * @return t_type Always returns UNKNOWN to chain msg and UNKNOWN in return.
 */
t_type	ft_perror_end(char *line);

#endif