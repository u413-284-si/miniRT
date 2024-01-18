/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entity_ACL.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:46 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/18 08:39:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

t_type	ft_check_ambient(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, 0.0, 1.0, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (AMBIENT);
}

t_type	ft_check_camera(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_unit_vec(&line, -1.0, 1.0))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, 0.0, 180.0, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (CAMERA);
}

t_type	ft_check_light(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, 0.0, 1.0, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (LIGHT);
}
