/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:23:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 17:50:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_parse_ambient(char *line, t_light *ambient)
{
	ft_parse_float(&line, &ambient->ratio);
	ft_parse_colour_block(&line, &ambient->colour);
}

void	ft_parse_camera(char *line, t_light *test)
{
	(void)line;
	(void)test;
}

void	ft_parse_light(char *line, t_light *light)
{
	ft_parse_float_block(&line, &light->pos);
	ft_parse_float(&line, &light->ratio);
	ft_parse_colour_block(&line, &light->colour);
}
