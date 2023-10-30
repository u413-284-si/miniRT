/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syscall_wrapper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:01:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/30 14:36:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_error.h"

/**
 * @brief Wrapper function for open() to print error.
 *
 * @param path		Path string to file to open.
 * @param flag		Flags given to open().
 * @param fd		File descriptor to assign to opened file.
 * @param msg		Message for perror.
 * @return int		New fd
 */
int	ft_err_open(const char *path, int flag, char *msg)
{
	int	fd;

	errno = 0;
	fd = open(path, flag);
	if (fd == -1)
	{
		ft_terminate(msg, errno);
	}
	return (fd);
}

/**
 * @brief Wrapper function for close to print error.
 *
 * @param fd		File descriptor of file to be closed.
 * @param msg		Message for perror.
 */
void	ft_err_close(int fd, char *msg)
{
	int	ret;

	errno = 0;
	ret = close(fd);
	if (ret == -1)
	{
		ft_terminate(msg, errno);
	}
}
