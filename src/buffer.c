/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:34:14 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/10 16:15:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file buffer.c
 * @brief Functions for handling the buffer.
 */
#include "buffer.h"

/**
 * @brief Initiates a t_buf buffer
 *
 * @param buf Pointer to buffer
 * @return t_err SUCCESS, ERROR
 */
t_err	ft_buf_init(t_buf *buf)
{
	buf->size = BUF_SIZE;
	if (ft_err_malloc((void **)&buf->str, buf->size))
		return (ERROR);
	ft_buf_clear(buf);
	return (SUCCESS);
}

/**
 * @brief Destroy the buffer.
 *
 * @param buf Pointer to buffer.
 */
void	ft_buf_destroy(t_buf *buf)
{
	free(buf->str);
	buf->str = NULL;
}

/**
 * @brief Set the buffer to zero.
 *
 * @param buf Pointer to buffer.
 */
void	ft_buf_clear(t_buf *buf)
{
	ft_memset(buf->str, '\0', buf->size);
	buf->cur_pos = buf->str;
}

/**
 * @brief Reallocs buffer into double its size
 *
 * @param buf Pointer to buffer.
 * @return t_err SUCCESS, ERROR
 */
t_err	ft_buf_double(t_buf *buf)
{
	char	*tmp_str;
	size_t	tmp_size;

	tmp_size = buf->size * 2;
	if (tmp_size < buf->size)
	{
		ft_putendl_fd("Error: maximum buffer size reached", 2);
		return (ERROR);
	}
	if (ft_err_malloc((void **)&tmp_str, tmp_size))
		return (ERROR);
	ft_memcpy(tmp_str, buf->str, buf->size);
	free (buf->str);
	buf->str = tmp_str;
	buf->cur_pos = buf->str + buf->size;
	buf->size *= 2;
	return (SUCCESS);
}

t_err	ft_buf_read(t_buf *buf, int fd)
{
	ssize_t	rd_bytes;

	rd_bytes = 0;
	while (1)
	{
		if (ft_err_read(fd, (void *)buf->cur_pos, buf->size, &rd_bytes))
			return (ERROR);
		if ((size_t)rd_bytes == buf->size)
		{
			if (ft_buf_double(buf))
				return (ERROR);
		}
		if (rd_bytes == 0)
			break ;
	}
	return (SUCCESS);
}