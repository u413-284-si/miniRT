/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:38:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 16:19:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	ft_parse_colour_block(char **line, t_colour *colour)
{
	size_t	offset;

	offset = 0;
	colour->r = ft_strtod(*line, &offset) / 255.0;
	*line += offset + 1;
	colour->g = ft_strtod(*line, &offset) / 255.0;
	*line += offset + 1;
	colour->b = ft_strtod(*line, &offset) / 255.0;
	*line += offset;
}

void	ft_parse_float(char **line, float *var)
{
	size_t	offset;

	offset = 0;
	*var = ft_strtod(*line, &offset);
	*line += offset;
	if (*(*line + 1) != '\0')
		(*line)++;
}

void	ft_parse_float_block(char **line, t_vec3 *vec3)
{
	ft_parse_float(line, &vec3->x);
	ft_parse_float(line, &vec3->y);
	ft_parse_float(line, &vec3->z);
}
