/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:02:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/12 17:50:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_err	ft_check_file(char *filename, char ***lines, int entity_count[6]);

t_err	ft_malloc_entities(t_entities *entities)
{
	if (ft_err_malloc((void **)entities->lsrc, sizeof(t_light) * entities->lsrc_count))
		return (ERROR);
	if (ft_err_malloc((void **)entities->obj, sizeof(t_shape) * entities->total))
	{
		free(entities->lsrc);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_parse_lines(t_entities *entities, char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*lines)
	{
		if (!ft_strncmp(*lines, "A ", 2))
			ft_parse_ambient(*lines + 2, &entities->ambient);
		else if (!ft_strncmp(*lines, "C ", 2))
			ft_parse_camera(*lines + 2, NULL);
		else if (!ft_strncmp(*lines, "L ", 2))
			ft_parse_light(*lines + 2, NULL);
		else if (!ft_strncmp(*lines, "sp ", 3))
			ft_parse_sphere(*lines + 3);
		else if (!ft_strncmp(*lines, "pl ", 3))
			ft_parse_plane(*lines + 3);
		else if (!ft_strncmp(*lines, "cy ", 3))
			ft_parse_cylinder(*lines + 3);
	}
}

t_err	ft_parse_file(char *filename, t_entities *entities)
{
	char		**lines;
	static int	entity_count[6];

	lines = NULL;
	if (ft_check_file(filename, &lines, entity_count))
		return (ERROR);
	entities->lsrc_count = entity_count[2];
	entities->total = entity_count[3] + entity_count[4] + entity_count[5];
	if (ft_malloc_entities(entities))
	{
		ft_free_array(lines);
		return (ERROR);
	}
	ft_parse_lines(entities, lines);
	ft_free_array(lines);
	return (SUCCESS);
}