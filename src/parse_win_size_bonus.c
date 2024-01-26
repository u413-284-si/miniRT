/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_win_size_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:02:02 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 15:09:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	ft_parse_win_size(char *line, t_vec2i *win_size)
{
	ft_parse_int(&line, &win_size->x);
	ft_parse_int(&line, &win_size->y);
}
