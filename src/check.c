/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 18:10:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

t_err	ft_check_lines(char **lines, int *lsrc_c, int *total)
{
	t_type		type;
	static int	ent_count[SUM_ENTS];
	size_t		i;

	i = 0;
	while (lines[i])
	{
		type = ft_check_line_type(lines[i++]);
		if (type == COMMENT)
			continue ;
		if (type == UNKNOWN || ft_incr_ent_count(ent_count, type))
		{
			ft_pinfo_line_number(i - 1);
			return (ERROR);
		}
	}
	if (ft_check_entity_count(ent_count))
		return (ERROR);
	*lsrc_c = ent_count[LIGHT];
	*total = ent_count[SPHERE] + ent_count[PLANE] + ent_count[CYLINDER];
	return (SUCCESS);
}

t_type	ft_check_line_type(char *line)
{
	if (*line == 'A')
		return (ft_check_ambient(line + 1));
	else if (*line == 'C')
		return (ft_check_camera(line + 1));
	else if (*line == 'L')
		return (ft_check_light(line + 1));
	else if (!ft_strncmp(line, "sp", 2))
		return (ft_check_sphere(line + 2));
	else if (!ft_strncmp(line, "pl", 2))
		return (ft_check_plane(line + 2));
	else if (!ft_strncmp(line, "cy", 2))
		return (ft_check_cylinder(line + 2));
	else if (*line == '#')
		return (COMMENT);
	else
		ft_perror("Line type not recognized", 0);
	return (UNKNOWN);
}

t_err	ft_incr_ent_count(int ent_count[SUM_ENTS], t_type type)
{
	static const int	ent_max[SUM_ENTS] = {
	[SPHERE] = SPHERE_MAX,
	[PLANE] = PLANE_MAX,
	[CYLINDER] = CYLINDER_MAX,
	[AMBIENT] = AMBIENT_MAX,
	[CAMERA] = CAMERA_MAX,
	[LIGHT] = LIGHT_MAX
	};

	ent_count[type]++;
	if (ent_count[type] > ent_max[type])
	{
		ft_perror_count(type, ent_max[type], ent_count[type], true);
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
