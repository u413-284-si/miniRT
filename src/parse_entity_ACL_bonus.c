/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity_ACL _bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:23:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 14:06:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	ft_parse_ambient(char *line, t_light *ambient)
{
	ft_parse_float(&line, &ambient->ratio);
	ft_parse_colour_block(&line, &ambient->colour);
}

void	ft_parse_camera(char *line, t_cam *cam)
{
	ft_parse_float_block(&line, &cam->look_from);
	ft_parse_float_block(&line, &cam->camera_direction);
	ft_parse_float(&line, &cam->hfov);
}

void	ft_parse_light(char *line, t_light *light)
{
	ft_parse_float_block(&line, &light->pos);
	ft_parse_float(&line, &light->ratio);
	ft_parse_colour_block(&line, &light->colour);
}
