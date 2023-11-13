/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:02:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 15:16:41 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_err	ft_malloc_ents(t_light **lsrc, t_hittable **obj, int lsrc_c, int total)
{
	if (ft_err_malloc((void **)*lsrc, sizeof(t_light) * lsrc_c))
		return (ERROR);
	if (ft_err_malloc((void **)*obj, sizeof(t_shape) * total))
	{
		free(*lsrc);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_parse_lines(t_entities *entities, char **lines)
{
	size_t	lights;
	size_t	id;

	lights = 0;
	id = 0;
	while (*lines)
	{
		if (**lines == 'A')
			ft_parse_ambient(*lines + 2, &entities->ambient);
		else if (**lines == 'C')
			ft_parse_camera(*lines + 2, NULL);
		else if (**lines == 'L')
			ft_parse_light(*lines + 2, &entities->lsrc[lights++]);
		else
		{
			if (**lines == 's')
				ft_parse_sphere(*lines + 3, &entities->obj[id], id);
			else if (**lines == 'p')
				ft_parse_plane(*lines + 3, &entities->obj[id], id);
			else if (**lines == 'c')
				ft_parse_cylinder(*lines + 3, &entities->obj[id], id);
			id++;
		}
		lines++;
	}
}

t_err	ft_parse_file(char *filename, t_entities *ents)
{
	char	**lines;

	lines = NULL;
	if (ft_check_file(filename, &lines, &ents->lsrc_count, &ents->total))
		return (ERROR);
	if (ft_malloc_ents(&ents->lsrc, &ents->obj, ents->lsrc_count, ents->total))
	{
		ft_free_array(lines);
		return (ERROR);
	}
	ft_parse_lines(ents, lines);
	ft_free_array(lines);
	return (SUCCESS);
}