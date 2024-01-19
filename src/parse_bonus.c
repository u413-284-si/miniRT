/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:02:54 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 18:11:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

t_err	ft_parse_file(char *filename, t_entities *scene, t_cam *cam)
{
	char	**lines;
	bool	is_bonus;
	t_err	err;

	lines = NULL;
	is_bonus = false;
	if (ft_import_file(filename, &lines))
		return (ERROR);
	if (!ft_strncmp(*lines, "#bonus", 6))
		is_bonus = true;
	if (is_bonus)
		err = ft_check_lines_bonus(lines, &scene->lsrc_count, &scene->total);
	else
		err = ft_check_lines(lines, &scene->lsrc_count, &scene->total);
	if (err)
	{
		ft_free_char_arr(lines);
		return (ERROR);
	}
	return (ft_store_data(scene, lines, is_bonus, cam));
}

t_err	ft_store_data(t_entities *scene, char **lines, bool is_bonus, \
	t_cam *cam)
{
	if (ft_malloc_ents(&scene->lsrc, &scene->obj,
			scene->lsrc_count, scene->total))
	{
		ft_free_char_arr(lines);
		return (ERROR);
	}
	if (is_bonus)
		ft_parse_lines_bonus(scene, cam, lines);
	else
	{
		ft_parse_lines(scene, cam, lines);
		ft_initialise_non_parsed(scene);
	}
	ft_free_char_arr(lines);
	return (SUCCESS);
}

void	ft_initialise_non_parsed(t_entities *scene)
{
	int	i;

	i = -1;
	while (++i < scene->total)
	{
		scene->obj[i].reflectivity = 0.0;
		scene->obj[i].shininess = 0;
		scene->obj[i].checkered = 0;
	}
}

void	ft_parse_entity_bonus(char *line, t_hittable *obj)
{
	static int	id = 0;

	if (*line == 's')
		ft_parse_sphere_bonus(line + 3, &obj[id], id);
	else if (*line == 'p')
		ft_parse_plane_bonus(line + 3, &obj[id], id);
	else if (!ft_strncmp(line, "cy ", 3))
		ft_parse_cylinder_bonus(line + 3, &obj[id], id);
	else if (!ft_strncmp(line, "co ", 3))
		ft_parse_cone_bonus(line + 3, &obj[id], id);
	id++;
}

void	ft_parse_lines_bonus(t_entities *scene, t_cam *cam, char **lines)
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
			ft_parse_entity_bonus(*lines, scene->obj);
		lines++;
	}
}
