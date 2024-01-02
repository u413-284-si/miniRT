/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity_ACL.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:23:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/01 18:55:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_parse_ambient(char *line, t_light *ambient)
{
	ft_parse_float(&line, &ambient->ratio);
	ft_parse_colour_block(&line, &ambient->colour);
}

void	ft_parse_camera(char *line, t_cam *cam)
{
	ft_parse_float_block(&line, &cam->centre);
	ft_parse_float_block(&line, &cam->direction);
	ft_parse_float(&line, &cam->hfov);
	cam->hfov = ft_degree_to_radian(cam->hfov);
}

void	ft_parse_light(char *line, t_light *light)
{
	ft_parse_float_block(&line, &light->pos);
	ft_parse_float(&line, &light->ratio);
	ft_parse_colour_block(&line, &light->colour);
}
