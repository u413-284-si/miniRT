/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 09:50:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

t_err	ft_check_lines(char **lines, int *lsrc_c, int *total)
{
	t_type	ent_type;
	static int	ent_count[SUM_ENTS];
	size_t		i;

	i = 0;
	while (lines[i])
	{
		ent_type = ft_check_line_type(lines[i]);
		if (ent_type == UNKNOWN
			|| ft_incr_ent_count(ent_count, ent_type))
		{
			ft_putstr_fd("Line number [ignoring empty lines]: <", 2);
			ft_putnbr_fd(i, 2);
			ft_putendl_fd(">", 2);
			return (ERROR);
		}
		i++;
	}
	ft_check_entity_count(ent_count);
	*lsrc_c = ent_count[LIGHT];
	*total = ent_count[SPHERE] + ent_count[PLANE] + ent_count[CYLINDER];
	return (SUCCESS);
}

t_type	ft_check_line_type(char *line)
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

t_err	ft_incr_ent_count(int ent_count[SUM_ENTS], t_type ent_type)
{
	static const int	ent_max[SUM_ENTS] = {
	[SPHERE] = SPHERE_MAX,
	[PLANE] = PLANE_MAX,
	[CYLINDER] = CYLINDER_MAX,
	[AMBIENT] = AMBIENT_MAX,
	[CAMERA] = CAMERA_MAX,
	[LIGHT] = LIGHT_MAX
	};

	ent_count[ent_type]++;
	if (ent_count[ent_type] > ent_max[ent_type])
	{
		ft_perror_count(ent_type, ent_max[ent_type], ent_count[ent_type], true);
		return (ERROR);
	}
	return (SUCCESS);
}

t_err	ft_check_entity_count(int ent_count[SUM_ENTS])
{
	t_type	missing;

	if (!ent_count[AMBIENT])
		missing = AMBIENT;
	else if (!ent_count[CAMERA])
		missing = CAMERA;
	else if (!ent_count[LIGHT])
		missing = LIGHT;
	else
		return (SUCCESS);
	ft_perror_count(missing, 0, 0, false);
	return (ERROR);
}
