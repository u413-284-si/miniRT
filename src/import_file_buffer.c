/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:34:14 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/14 07:35:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import_file.h"

t_err	ft_buf_init(t_buf *buf)
{
	buf->size = BUF_SIZE;
	if (ft_err_malloc((void **)&buf->str, buf->size))
		return (ERROR);
	ft_buf_clear(buf);
	return (SUCCESS);
}

void	ft_buf_destroy(t_buf *buf)
{
	free(buf->str);
	buf->str = NULL;
}

void	ft_buf_clear(t_buf *buf)
{
	ft_memset(buf->str, '\0', buf->size);
	buf->cur_pos = 0;
}

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
	buf->size *= 2;
	return (SUCCESS);
}

t_err	ft_buf_read_file(t_buf *buf, int fd)
{
	ssize_t	rd_bytes;
	char	*cur_str;
	size_t	cur_read;

	rd_bytes = 0;
	while (1)
	{
		cur_str = buf->str + buf->cur_pos;
		cur_read = buf->size - buf->cur_pos;
		if (ft_err_read(fd, (void *)cur_str, cur_read, &rd_bytes))
			return (ERROR);
		buf->cur_pos += rd_bytes;
		if ((size_t)rd_bytes == cur_read)
		{
			if (ft_buf_double(buf))
				return (ERROR);
		}
		if (rd_bytes == 0)
			break ;
	}
	buf->str[buf->cur_pos++] = '\0';
	return (SUCCESS);
}
