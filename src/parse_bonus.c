/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:02:54 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 10:29:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

t_err	ft_parse_file(char *filename, t_entities *scene, t_cam *cam,
			t_vec2i *win_size)
{
	char	**lines;
	bool	is_bonus;

	lines = NULL;
	if (ft_import_file(filename, &lines))
		return (ERROR);
	is_bonus = !ft_strncmp(*lines, "#bonus", 6);
	if (ft_choose_check_ft(lines, &scene->lsrc_count, &scene->total, is_bonus))
		return (ERROR);
	if (ft_malloc_ents(&scene->lsrc, &scene->obj, scene->lsrc_count,
			scene->total))
	{
		ft_free_char_arr(lines);
		return (ERROR);
	}
	if (is_bonus)
		ft_parse_lines_bonus(lines, scene, cam, win_size);
	else
	{
		ft_parse_lines(lines, scene, cam, win_size);
		ft_initialise_non_parsed(scene);
	}
	ft_free_char_arr(lines);
	return (SUCCESS);
}

t_err	ft_choose_check_ft(char **lines, int *lsrc_c, int *total, bool is_bonus)
{
	t_err	err;

	if (is_bonus)
		err = ft_check_lines_bonus(lines, lsrc_c, total);
	else
		err = ft_check_lines(lines, lsrc_c, total);
	if (err)
	{
		ft_free_char_arr(lines);
		return (ERROR);
	}
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

void	ft_parse_lines_bonus(char **lines, t_entities *scene, t_cam *cam,
			t_vec2i *win_size)
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
		else if (**lines == 'S')
			ft_parse_win_size(*lines + 2, win_size);
		else if (**lines != '#')
			ft_parse_entity_bonus(*lines, scene->obj);
		lines++;
	}
	if (win_size->x == 0)
		win_size->x = WIN_SIZE_X;
	if (win_size->y == 0)
		win_size->y = WIN_SIZE_Y;
}
