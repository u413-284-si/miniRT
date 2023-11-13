/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_import.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:40:15 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 17:49:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

t_err	ft_validate_import(char *filename, char ***lines)
{
	int	fd;

	if (!ft_isvalid_filename(filename))
		return (ERROR);
	fd = 0;
	if (ft_err_open(filename, O_RDONLY, &fd))
		return (ERROR);
	if (ft_import_file(fd, lines))
		return (ERROR);
	if (ft_err_close(fd))
	{
		ft_free_array(*lines);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_import_file(int fd, char ***lines)
{
	t_buf	buf;

	if (ft_buf_init(&buf))
		return (ERROR);
	if (ft_buf_read_file(&buf, fd))
	{
		ft_buf_destroy(&buf);
		return (ERROR);
	}
	errno = 0;
	*lines = ft_split(buf.str, '\n');
	if (errno)
		ft_perror("malloc() failed", errno);
	ft_buf_destroy(&buf);
	if (*lines == NULL)
		return (ERROR);
	return (SUCCESS);
}

bool	ft_isvalid_filename(char *filename)
{
	int		len;
	char	*start;

	start = ft_strrchr(filename, '/');
	if (!start)
		start = filename;
	else
		start += 1;
	len = ft_strlen(start);
	if (!ft_strnstr(start + len - 3, ".rt", len))
	{
		ft_perror("Wrong file extension", 0);
		return (false);
	}
	return (true);
}
