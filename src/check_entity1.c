/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entity1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/10 19:28:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

bool	ft_check_ambient(char *line)
{
	ft_skip_space(&line);
	if (!ft_is_valid_float(&line))
		return (false);
	ft_skip_space(&line);
	if (!ft_is_valid_rgb_block(&line))
		return (false);
	return (true);
}

bool	ft_check_camera(char *line)
{
	ft_skip_space(&line);
	if (!ft_is_valid_float_block(&line))
		return (false);
	ft_skip_space(&line);
	if (!ft_is_valid_float_block(&line))
		return (false);
	ft_skip_space(&line);
	if (!ft_is_valid_float(&line))
		return (false);
	return (true);
}

bool	ft_check_light(char *line)
{
	ft_skip_space(&line);
	if (!ft_is_valid_float_block(&line))
		return (false);
	ft_skip_space(&line);
	if (!ft_is_valid_float(&line))
		return (false);
	ft_skip_space(&line);
	if (!ft_is_valid_rgb_block(&line))
		return (false);
	return (true);
}