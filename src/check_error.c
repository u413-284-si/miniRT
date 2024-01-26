/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:28 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 18:07:05 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

#ifndef IS_BONUS

void	ft_perror_count(t_type type, int max, int count, bool high)
{
	static const char	*entity_name[SUM_ENTS] = {
	[SPHERE] = "sphere (sp)",
	[PLANE] = "plane (pl)",
	[CYLINDER] = "cylinder (cy)",
	[AMBIENT] = "ambient light (A)",
	[CAMERA] = "camera (C)",
	[LIGHT] = "light (L)"
	};

	ft_putendl_fd("Error", 2);
	if (high)
		ft_putstr_fd("Too many entities of type <", 2);
	else
		ft_putstr_fd("Missing entity of type <", 2);
	ft_putstr_fd((char *)entity_name[type], 2);
	ft_putendl_fd(">", 2);
	if (!high)
		return ;
	ft_putstr_fd("Expected: ", 2);
	ft_putnbr_fd(max, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("But got:  ", 2);
	ft_putnbr_fd(count, 2);
	ft_putendl_fd("", 2);
}
#endif

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
		ft_putendl_fd(MSG_EXP_FLOAT, 2);
	else
		ft_putendl_fd(MSG_EXP_INT, 2);
	return (false);
}

bool	ft_perror_separator(char *line, bool comma)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Separator not recognized: -->", 2);
	ft_putendl_fd(line, 2);
	if (comma)
		ft_putendl_fd(MSG_EXP_COMMA, 2);
	else
		ft_putendl_fd(MSG_EXP_SPACE, 2);
	return (false);
}

t_type	ft_perror_end(char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Not recognized line end: -->", 2);
	ft_putendl_fd(line, 2);
	ft_putendl_fd(MSG_EXP_END, 2);
	return (UNKNOWN);
}
