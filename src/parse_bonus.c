/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:02:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/30 00:58:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

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

t_err	ft_malloc_ents(t_light **lsrc, t_hittable **obj, int lsrc_c, int total)
{
	if (ft_err_malloc((void **)lsrc, sizeof(**lsrc) * lsrc_c))
		return (ERROR);
	if (ft_err_malloc((void **)obj, sizeof(**obj) * total))
	{
		free(*lsrc);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ft_parse_lines(t_entities *scene, t_cam *cam, char **lines)
{
	size_t	lights;
	size_t	id;

	lights = 0;
	id = 0;
	while (*lines)
	{
		if (**lines == 'A')
			ft_parse_ambient(*lines + 2, &scene->ambient);
		else if (**lines == 'C')
			ft_parse_camera(*lines + 2, cam);
		else if (**lines == 'L')
			ft_parse_light(*lines + 2, &scene->lsrc[lights++]);
		else if (**lines != '#')
		{
			if (**lines == 's')
				ft_parse_sphere(*lines + 3, &scene->obj[id], id);
			else if (**lines == 'p')
				ft_parse_plane(*lines + 3, &scene->obj[id], id);
			else if (!ft_strncmp(*lines, "cy ", 3))
				ft_parse_cylinder(*lines + 3, &scene->obj[id], id);
			else if (!ft_strncmp(*lines, "co ", 3))
				ft_parse_cone(*lines + 3, &scene->obj[id], id);
			id++;
		}
		lines++;
	}
}