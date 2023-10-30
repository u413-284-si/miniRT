/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syscall_wrapper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:01:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/30 15:08:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_error.h"

/**
 * @brief Wrapper function for open() to print error.
 *
 * @param path		Path string to file to open.
 * @param flag		Flags given to open().
 * @param fd		File descriptor to assign to opened file.
 */
bool	ft_err_open(const char *path, int flag, int *fd)
{
	errno = 0;
	*fd = open(path, flag);
	if (*fd == -1)
	{
		return (true);
	}
	return (false);
}

/**
 * @brief Wrapper function for close to print error.
 *
 * @param fd		File descriptor of file to be closed.
 * @param msg		Message for perror.
 */
bool	ft_err_close(int fd)
{
	int	ret;

	errno = 0;
	ret = close(fd);
	if (ret == -1)
	{
		return (true);
	}
	return (false);
}
