/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:27:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 11:33:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_rm_space(char **str)
{
	char	*begin;
	char	*end;

	if (**str == ' ')
		(*str)++;
	begin = *str;
	end = *str;
	while (*end == ' ')
		end++;
	while (*end)
		*begin++ = *end++;
	*begin = '\0';
}

bool	ft_is_valid_float(char **line, float min, float max)
{
	size_t	offset;
	double	num;
	char	*tmp;

	offset = 0;
	num = ft_strtod(*line, &offset);
	if (offset == 0)
		return (false);
	if (fabs(num) < min)
		return (false);
	if (num < min || num > max)
		return (false);
	tmp = *line + offset;
	if (*tmp != ',' && *tmp != ' ' && *tmp != '\0')
		return (false);
	*line = tmp;
	return (true);
}

bool	ft_is_valid_float_block(char **line, float min, float max)
{
	if (!ft_is_valid_float(line, min, max))
		return (false);
	if (**line != ',')
		return (false);
	(*line)++;
	if (!ft_is_valid_float(line, min, max))
		return (false);
	if (**line != ',')
		return (false);
	(*line)++;
	if (!ft_is_valid_float(line, min, max))
		return (false);
	if (**line != ' ' && **line != '\0')
		return (false);
	return (true);
}

bool	ft_is_valid_rgb_val(char **line)
{
	int	tmp;

	tmp = 0;
	while (ft_isdigit(**line) && tmp < 255)
	{
		tmp *= 10;
		tmp += **line - '0';
		(*line)++;
	}
	if (tmp <= 255 && (**line == ',' || **line == ' ' || **line == '\0'))
		return (true);
	return (false);
}

bool	ft_is_valid_rgb_block(char **line)
{
	if (!ft_is_valid_rgb_val(line))
		return (false);
	if (**line != ',')
		return (false);
	(*line)++;
	if (!ft_is_valid_rgb_val(line))
		return (false);
	if (**line != ',')
		return (false);
	(*line)++;
	if (!ft_is_valid_rgb_val(line))
		return (false);
	if (**line != ' ' && **line != '\0')
		return (false);
	return (true);
}