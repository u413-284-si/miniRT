/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 16:29:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

t_err	ft_check_file(char *argv, char ***lines, int *lsrc_c, int *total)
{
	if (ft_validate_import(argv, lines))
		return (ERROR);
	if (ft_check_lines(*lines, lsrc_c, total))
	{
		ft_free_array(*lines);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_check_lines(char **lines, int *lsrc_c, int *total)
{
	t_ent_type	ent_type;
	static int	ent_count[SUM_ENTS];
	size_t		i;

	i = 0;
	while (lines[i])
	{
		ent_type = ft_check_line_type(lines[i]);
		if (ent_type == UNKNOWN
			|| ft_incr_ent_count(ent_count, ent_type))
		{
			ft_putstr_fd("Line number: <", 2);
			ft_putnbr_fd(i, 2);
			ft_putendl_fd(">", 2);
			return (ERROR);
		}
		i++;
	}
	*lsrc_c = ent_count[LIGHT];
	*total = ent_count[SPHERE] + ent_count[PLANE] + ent_count[CYLINDER];
	return (SUCCESS);
}

t_ent_type	ft_check_line_type(char *line)
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

t_err	ft_incr_ent_count(int ent_count[SUM_ENTS], t_ent_type ent_type)
{
	static const int	ent_max[SUM_ENTS] = {
	[AMBIENT] = AMBIENT_MAX,
	[CAMERA] = CAMERA_MAX,
	[LIGHT] = LIGHT_MAX,
	[SPHERE] = SPHERE_MAX,
	[PLANE] = PLANE_MAX,
	[CYLINDER] = CYLINDER_MAX
	};

	ent_count[ent_type]++;
	if (ent_count[ent_type] > ent_max[ent_type])
	{
		ft_perror_count(ent_type, ent_max[ent_type], ent_count[ent_type]);
		return (ERROR);
	}
	return (SUCCESS);
}
