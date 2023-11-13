/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 11:27:40 by gwolf            ###   ########.fr       */
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

bool	ft_check_filename(char *filename)
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
		return (true);
	}
	return (false);
}

t_err	ft_check_file(char *filename, char ***lines, int entity_count[ENTITIES])
{
	int	fd;

	if (ft_check_filename(filename))
		ft_terminate("Wrong file extension", 0);
	fd = 0;
	if (ft_err_open(filename, O_RDONLY, &fd))
		ft_terminate("Open() failed", errno);
	if (ft_import_file(fd, lines))
		ft_terminate("Could not import file", errno);
	if (ft_err_close(fd))
		ft_terminate("Close() failed", errno);
	if (ft_check_line(*lines, entity_count))
	{
		ft_free_array(*lines);
		ft_terminate("Not correctly formatted", 0);
	}
	return (SUCCESS);
}

void	ft_perror_count(t_entity_type type, int max, int count)
{
	static const char	*entity_name[ENTITIES] =	{
	[AMBIENT] = "ambient light",
	[CAMERA] = "camera",
	[LIGHT] = "light",
	[SPHERE] = "sphere",
	[PLANE] = "plane",
	[CYLINDER] = "cylinder"
	};

	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Too many entities of type ", 2);
	ft_putendl_fd((char *)entity_name[type], 2);
	ft_putnbr_fd(max, 2);
	ft_putstr_fd(" expected / ", 2);
	ft_putnbr_fd(count, 2);
	ft_putendl_fd(" got ", 2);
}

t_err	ft_incr_entity_count(int entity_count[ENTITIES], t_entity_type entity_type)
{
	static const int	entity_max[ENTITIES] =	{
	[AMBIENT] = AMBIENT_MAX,
	[CAMERA] = CAMERA_MAX,
	[LIGHT] = LIGHT_MAX,
	[SPHERE] = SPHERE_MAX,
	[PLANE] = PLANE_MAX,
	[CYLINDER] = CYLINDER_MAX
	};

	entity_count[entity_type]++;
	if (entity_count[entity_type] > entity_max[entity_type])
	{
		ft_perror_count(entity_type, entity_max[entity_type], entity_count[entity_type]);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_check_line(char **lines, int entity_count[ENTITIES])
{
	t_entity_type	entity_type;

	while (*lines)
	{
		entity_type = ft_is_valid_line(*lines);
		if (entity_type == UNKNOWN
			|| ft_incr_entity_count(entity_count, entity_type))
		{
			ft_putendl_fd("This following line is bad", 2);
			ft_putendl_fd(*lines, 2);
			return (ERROR);
		}
		lines++;
	}
	return (SUCCESS);
}

t_entity_type	ft_is_valid_line(char *line)
{
	if (!ft_strncmp(line, "A ", 2))
		return (ft_check_ambient(line + 1));
	else if (!ft_strncmp(line, "C ", 2))
		return (ft_check_camera(line + 1));
	else if (!ft_strncmp(line, "L ", 2))
		return (ft_check_light(line + 1));
	else if (!ft_strncmp(line, "sp ", 3))
		return (ft_check_sphere(line + 2));
	else if (!ft_strncmp(line, "pl ", 3))
		return (ft_check_plane(line + 2));
	else if (!ft_strncmp(line, "cy ", 3))
		return (ft_check_cylinder(line + 2));
	return (UNKNOWN);
}

