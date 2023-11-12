/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:23:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/12 17:48:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

double	ft_strtod(const char *str, size_t *offset);

void	ft_parse_ambient(char *line, t_light *ambient)
{
	size_t	offset;

	offset = 0;
	ft_skip_space(&line);
	ambient->ratio = ft_strtod(line, &offset);
	line += offset;
	ambient->colour.r = ft_atoi(line) / 255.0;
	line = ft_strchr(line, ',') + 1;
	ambient->colour.g = ft_atoi(line) / 255.0;
	line = ft_strchr(line, ',') + 1;
	ambient->colour.b = ft_atoi(line) / 255.0;
}

void	ft_parse_camera(char *line, t_light *test)
{
	(void)line;
	(void)test;
}

void	ft_parse_light(const char *line, t_light *light)
{
	(void)line;
	(void)light;
}