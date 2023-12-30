/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entity_sp_pl_cy_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/30 00:31:57 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

t_type	ft_check_sphere(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (SPHERE);
}

t_type	ft_check_plane(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (PLANE);
}

t_type	ft_check_cylinder(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (CYLINDER);
}

t_type	ft_check_cone(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (CONE);
}
