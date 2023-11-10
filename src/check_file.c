/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/10 19:17:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "ft_lst.h"
#include "buffer.h"

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
	*lines = ft_split(buf.str, '\n');
	ft_buf_destroy(&buf);
	if (*lines == NULL)
		return (ERROR);
	return (SUCCESS);
}

bool	ft_check_filename(char *argv)
{
	int		len;
	char	*start;

	start = ft_strrchr(argv, '/');
	if (!start)
		start = argv;
	else
		start += 1;
	len = ft_strlen(start);
	if (!ft_strnstr(start + len - 3, ".rt", len))
	{
		return (true);
	}
	return (false);
}

void	ft_check_file(char *argv)
{
	int	fd;
	char **lines;

	if (ft_check_filename(argv))
		ft_terminate("Wrong file extension", 0);
	fd = 0;
	if (ft_err_open(argv, O_RDONLY, &fd))
		ft_terminate("Open() failed", errno);
	lines = NULL;
	if (ft_import_file(fd, &lines))
		ft_terminate("Could not import file", errno);
	if (ft_check_line(lines))
	{
		//free array
		ft_terminate("Not correctly formatted", 0);
	}
	if (ft_err_close(fd))
		ft_terminate("Close() failed", errno);
}

t_err	ft_check_line(char **lines)
{
	while (*lines)
	{
		if (!ft_is_valid_line(*lines))
			return (ERROR);
		lines++;
	}
	return (SUCCESS);
}

bool	ft_is_valid_line(char *line)
{
	if (!ft_strncmp(line, "A ", 2))
		return (ft_check_ambient(line + 2));
	else if (!ft_strncmp(line, "C ", 2))
		return (ft_check_camera(line + 2));
	else if (!ft_strncmp(line, "L ", 2))
		return (ft_check_light(line + 2));
	else if (!ft_strncmp(line, "sp ", 3))
		return (ft_check_sphere(line + 3));
	else if (!ft_strncmp(line, "pl ", 3))
		return (ft_check_plane(line + 3));
	else if (!ft_strncmp(line, "cy ", 3))
		return (ft_check_cylinder(line + 3));
	return (false);
}

