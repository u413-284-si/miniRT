/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 10:17:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

t_err	ft_check_lines_bonus(char **lines, int *lsrc_c, int *total)
{
	t_type		type;
	static int	ent_count[SUM_ENTS];
	size_t		i;

	i = 0;
	while (lines[i])
	{
		type = ft_check_line_type_bonus(lines[i++]);
		if (type == COMMENT || type == WIN_SIZE)
			continue ;
		if (type == UNKNOWN
			|| ft_incr_ent_count_bonus(ent_count, type))
		{
			ft_perror_number("Line number [ignoring empty lines]", i - 1);
			return (ERROR);
		}
	}
	if (ft_check_entity_count(ent_count))
		return (ERROR);
	*lsrc_c = ent_count[LIGHT];
	*total = ent_count[SPHERE] + ent_count[PLANE] + ent_count[CYLINDER] + \
		ent_count[CONE];
	return (SUCCESS);
}

t_type	ft_check_line_type_bonus(char *line)
{
	if (*line == 'A')
		return (ft_check_ambient(line + 1));
	else if (*line == 'C')
		return (ft_check_camera(line + 1));
	else if (*line == 'L')
		return (ft_check_light(line + 1));
	else if (*line == 'S')
		return (ft_check_win_size(line + 1));
	else if (!ft_strncmp(line, "sp", 2))
		return (ft_check_sphere_bonus(line + 2));
	else if (!ft_strncmp(line, "pl", 2))
		return (ft_check_plane_bonus(line + 2));
	else if (!ft_strncmp(line, "cy", 2))
		return (ft_check_cylinder_bonus(line + 2));
	else if (!ft_strncmp(line, "co", 2))
		return (ft_check_cone_bonus(line + 2));
	else if (*line == '#')
		return (COMMENT);
	else
		ft_perror("Line type not recognized", 0);
	return (UNKNOWN);
}

t_err	ft_incr_ent_count_bonus(int ent_count[SUM_ENTS], t_type type)
{
	static const int	ent_max[SUM_ENTS] = {
	[SPHERE] = SPHERE_MAX,
	[PLANE] = PLANE_MAX,
	[CYLINDER] = CYLINDER_MAX,
	[CONE] = CONE_MAX,
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
