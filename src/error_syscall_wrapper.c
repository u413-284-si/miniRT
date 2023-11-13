/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syscall_wrapper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:01:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 14:26:57 by gwolf            ###   ########.fr       */
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
t_err	ft_err_open(const char *path, int flag, int *fd)
{
	errno = 0;
	*fd = open(path, flag);
	if (*fd == -1)
	{
		ft_perror("open() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}

/**
 * @brief Wrapper function for close to print error.
 *
 * @param fd		File descriptor of file to be closed.
 * @param msg		Message for perror.
 */
t_err	ft_err_close(int fd)
{
	int	ret;

	errno = 0;
	ret = close(fd);
	if (ret == -1)
	{
		ft_perror("close() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_err_malloc(void **ptr, size_t size)
{
	errno = 0;
	*ptr = malloc(size);
	if (*ptr == NULL)
	{
		ft_perror("malloc() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_err_read(int fd, void *buf, size_t size, ssize_t *rd_bytes)
{
	errno = 0;
	*rd_bytes = read(fd, buf, size);
	if (*rd_bytes == -1)
	{
		ft_perror("read() failed", errno);
		return (ERROR);
	}
	return (SUCCESS);
}
