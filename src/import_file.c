/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:40:15 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 14:00:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import_file.h"

t_err	ft_import_file(char *filename, char ***lines)
{
	int	fd;

	if (!ft_isvalid_filename(filename))
		return (ERROR);
	fd = 0;
	if (ft_err_open(filename, O_RDONLY, &fd))
		return (ERROR);
	if (ft_read_and_split(fd, lines))
		return (ERROR);
	if (ft_err_close(fd))
	{
		ft_free_char_arr(*lines);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_read_and_split(int fd, char ***lines)
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

	len = ft_strlen(filename);
	if (ft_strncmp(filename + len - 3, ".rt", 3))
	{
		ft_perror("Wrong file extension. Please provide a .rt file", 0);
		return (false);
	}
	return (true);
}
