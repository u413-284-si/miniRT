/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entity1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/12 14:46:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

t_entity_type	ft_check_ambient(char *line)
{
	ft_skip_space(&line);
	if (!ft_is_valid_float(&line, 0.0, 1.0))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (!ft_is_valid_rgb_block(&line))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (*line != '\0')
		return (UNKNOWN);
	return (AMBIENT);
}

t_entity_type	ft_check_camera(char *line)
{
	ft_skip_space(&line);
	if (!ft_is_valid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (!ft_is_valid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (!ft_is_valid_float(&line, 0.0, 180.0))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (*line != '\0')
		return (UNKNOWN);
	return (CAMERA);
}

t_entity_type	ft_check_light(char *line)
{
	ft_skip_space(&line);
	if (!ft_is_valid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (!ft_is_valid_float(&line, 0.0, 1.0))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (!ft_is_valid_rgb_block(&line))
		return (UNKNOWN);
	ft_skip_space(&line);
	if (*line != '\0')
		return (UNKNOWN);
	return (LIGHT);
}