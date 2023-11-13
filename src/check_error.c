/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 17:57:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_perror_count(t_ent_type type, int max, int count)
{
	static const char	*entity_name[SUM_ENTS] = {
	[AMBIENT] = "ambient light",
	[CAMERA] = "camera",
	[LIGHT] = "light",
	[SPHERE] = "sphere",
	[PLANE] = "plane",
	[CYLINDER] = "cylinder"
	};

	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Too many entities of type ", 2);
	ft_putendl_fd((char *)entity_name[type], 2);
	ft_putnbr_fd(max, 2);
	ft_putstr_fd(" expected / ", 2);
	ft_putnbr_fd(count, 2);
	ft_putendl_fd(" got ", 2);
}

bool	ft_perror_range(char *line, size_t offset, int min, int max)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Out of range: <", 2);
	*(line + offset) = '\0';
	ft_putstr_fd(line, 2);
	ft_putendl_fd(">", 2);
	ft_putstr_fd("Expected range: [", 2);
	ft_putnbr_fd(min, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(max, 2);
	ft_putendl_fd("]", 2);
	return (false);
}

bool	ft_perror_convert(char *line, bool is_float)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Conversion failed here: -->", 2);
	ft_putendl_fd(line, 2);
	if (is_float)
		ft_putendl_fd("Expected: valid float (1.2 or 3)", 2);
	else
		ft_putendl_fd("Expected: positive int (1 or 23)", 2);
	return (false);
}

bool	ft_perror_separator(char *line, bool comma)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Separator not recognized: -->", 2);
	ft_putendl_fd(line, 2);
	if (comma)
		ft_putendl_fd("Expected: comma ','", 2);
	else
		ft_putendl_fd("Expected: space ' ' or zero terminator '\\0'", 2);
	return (false);
}

t_ent_type	ft_perror_end(char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Not recognized line end: -->", 2);
	ft_putendl_fd(line, 2);
	ft_putendl_fd("Expected: space ' ' or nothing", 2);
	return (UNKNOWN);
}
