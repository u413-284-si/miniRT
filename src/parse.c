/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:02:54 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/25 00:32:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#ifndef IS_BONUS

t_err	ft_parse_file(char *filename, t_entities *scene, t_cam *cam)
{
	char	**lines;

	lines = NULL;
	if (ft_import_file(filename, &lines))
		return (ERROR);
	if (ft_check_lines(lines, &scene->lsrc_count, &scene->total))
	{
		ft_free_char_arr(lines);
		return (ERROR);
	}
	if (ft_malloc_ents(&scene->lsrc, &scene->obj,
			scene->lsrc_count, scene->total))
	{
		ft_free_char_arr(lines);
		return (ERROR);
	}
	ft_parse_lines(scene, cam, lines);
	ft_free_char_arr(lines);
	return (SUCCESS);
}
#endif

t_err	ft_malloc_ents(t_light **lsrc, t_hittable **obj, int lsrc_c, int total)
{
	if (ft_err_malloc((void **)lsrc, sizeof(**lsrc) * lsrc_c))
		return (ERROR);
	if (total == 0)
		return (SUCCESS);
	if (ft_err_malloc((void **)obj, sizeof(**obj) * total))
	{
		free(*lsrc);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_parse_entity(char *line, t_hittable *obj)
{
	static int	id = 0;

	if (*line == 's')
		ft_parse_sphere(line + 3, &obj[id], id);
	else if (*line == 'p')
		ft_parse_plane(line + 3, &obj[id], id);
	else if (*line == 'c')
		ft_parse_cylinder(line + 3, &obj[id], id);
	id++;
}

void	ft_parse_lines(t_entities *scene, t_cam *cam, char **lines)
{
	static int	light_id = 0;

	while (*lines)
	{
		if (**lines == 'A')
			ft_parse_ambient(*lines + 2, &scene->ambient);
		else if (**lines == 'C')
			ft_parse_camera(*lines + 2, cam);
		else if (**lines == 'L')
		{
			ft_parse_light(*lines + 2, &scene->lsrc[light_id], light_id);
			light_id++;
		}
		else if (**lines != '#')
			ft_parse_entity(*lines, scene->obj);
		lines++;
	}
}
