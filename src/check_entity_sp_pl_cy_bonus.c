/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entity_sp_pl_cy_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:46 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 17:59:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

t_type	ft_check_sphere_bonus(char *line)
{
	int	i;

	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	i = -1;
	while (++i < 4)
	{
		ft_rm_space(&line);
		if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
			return (UNKNOWN);
	}
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (SPHERE);
}

t_type	ft_check_plane_bonus(char *line)
{
	int	i;

	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	i = -1;
	while (++i < 3)
	{
		ft_rm_space(&line);
		if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
			return (UNKNOWN);
	}
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (PLANE);
}

t_type	ft_check_cylinder_bonus(char *line)
{
	int	i;

	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	i = -1;
	while (++i < 5)
	{
		ft_rm_space(&line);
		if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
			return (UNKNOWN);
	}
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (CYLINDER);
}

t_type	ft_check_cone_bonus(char *line)
{
	int	i;

	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, FLOAT_MIN, FLOAT_MAX))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (!ft_isvalid_float_block(&line, -1.0, 1.0))
		return (UNKNOWN);
	i = -1;
	while (++i < 5)
	{
		ft_rm_space(&line);
		if (!ft_isvalid_float(&line, FLOAT_MIN, FLOAT_MAX, false))
			return (UNKNOWN);
	}
	ft_rm_space(&line);
	if (!ft_isvalid_rgb_block(&line))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (CONE);
}
