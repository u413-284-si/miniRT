/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:27:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/10 19:22:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_skip_space(char **line)
{
	while (**line == ' ')
		(*line)++;
}

bool	ft_is_valid_float(char **line)
{
	if (**line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == ',' || **line == ' ' || **line == '\0')
		return (true);
	if (**line != '.')
		return (false);
	(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == ',' || **line == ' ' || **line == '\0')
		return (true);
	return (false);
}

bool	ft_is_valid_float_block(char **line)
{
	if (!ft_is_valid_float(line))
		return (false);
	if (**line != ',')
		return (false);
	(*line)++;
	if (!ft_is_valid_float(line))
	return (false);
	if (**line != ',')
		return (false);
	(*line)++;
	if (!ft_is_valid_float(line))
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