/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:27:34 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

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
	if (!comma && **line != ' ' && **line != '\t' && **line != '\0')
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

bool	ft_isvalid_unit_vec(char **line, float min, float max)
{
	double	checksum;
	double	ret;
	size_t	offset;
	char	*begin;
	char	*tmp;

	begin = *line;
	if (ft_isvalid_float_block(line, min, max) == false)
		return (false);
	tmp = begin;
	offset = 0;
	checksum = 0;
	ret = ft_strtod(tmp, &offset);
	checksum += ret * ret;
	tmp += offset + 1;
	ret = ft_strtod(tmp, &offset);
	checksum += ret * ret;
	tmp += offset + 1;
	ret = ft_strtod(tmp, &offset);
	checksum += ret * ret;
	if (checksum == 0.0)
		return (ft_perror_not_unit(begin));
	else if (checksum > 1.0)
		ft_pwarning_not_unit(begin);
	return (true);
}

bool	ft_isvalid_int(char **line, int min, int max, bool comma)
{
	int	tmp;

	tmp = 0;
	if (!ft_isdigit(**line))
		return (ft_perror_convert(*line, false));
	tmp = ft_atoi(*line);
	if (tmp < min || tmp > max)
		return (ft_perror_range(*line, 3, min, max));
	while (ft_isdigit(**line))
		(*line)++;
	if (comma && **line != ',')
		return (ft_perror_separator(*line, comma));
	if (!comma && **line != ' ' && **line != '\t' && **line != '\0')
		return (ft_perror_separator(*line, comma));
	return (true);
}

bool	ft_isvalid_rgb_block(char **line)
{
	if (!ft_isvalid_int(line, 0, 255, true))
		return (false);
	(*line)++;
	if (!ft_isvalid_int(line, 0, 255, true))
		return (false);
	(*line)++;
	if (!ft_isvalid_int(line, 0, 255, false))
		return (false);
	return (true);
}
