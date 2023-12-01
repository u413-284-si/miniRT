/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:27:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/25 18:36:31 by gwolf            ###   ########.fr       */
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
	if (begin == end)
		return ;
	while (*end)
		*begin++ = *end++;
	*begin = '\0';
}

bool	ft_isvalid_float(char **line, float min, float max, bool comma)
{
	size_t	offset;
	double	num;

	offset = 0;
	num = ft_strtod(*line, &offset);
	if (offset == 0)
		return (ft_perror_convert(*line, true));
	if (num < min || num > max)
		return (ft_perror_range(*line, offset, (int)min, (int)max));
	*line += offset;
	if (comma && **line != ',')
		return (ft_perror_separator(*line, comma));
	if (!comma && **line != ' ' && **line != '\0')
		return (ft_perror_separator(*line, comma));
	return (true);
}

bool	ft_isvalid_float_block(char **line, float min, float max)
{
	if (!ft_isvalid_float(line, min, max, true))
		return (false);
	(*line)++;
	if (!ft_isvalid_float(line, min, max, true))
		return (false);
	(*line)++;
	if (!ft_isvalid_float(line, min, max, false))
		return (false);
	return (true);
}

bool	ft_isvalid_rgb_val(char **line, bool comma)
{
	int	tmp;

	tmp = 0;
	if (!ft_isdigit(**line))
		return (ft_perror_convert(*line, false));
	while (ft_isdigit(**line) && tmp < 255)
	{
		tmp *= 10;
		tmp += **line - '0';
		(*line)++;
	}
	if (tmp > 255)
		return (ft_perror_range(*line - 3, 3, 0, 255));
	if (comma && **line != ',')
		return (ft_perror_separator(*line, comma));
	if (!comma && **line != ' ' && **line != '\0')
		return (ft_perror_separator(*line, comma));
	return (true);
}

bool	ft_isvalid_rgb_block(char **line)
{
	if (!ft_isvalid_rgb_val(line, true))
		return (false);
	(*line)++;
	if (!ft_isvalid_rgb_val(line, true))
		return (false);
	(*line)++;
	if (!ft_isvalid_rgb_val(line, false))
		return (false);
	return (true);
}
