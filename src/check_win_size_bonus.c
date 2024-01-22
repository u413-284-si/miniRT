/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_size_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:04:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 15:11:33 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

t_type	ft_check_win_size(char *line)
{
	ft_rm_space(&line);
	if (!ft_isvalid_int(&line, WIN_SIZE_X, 2000, true))
		return (UNKNOWN);
	line++;
	if (!ft_isvalid_int(&line, WIN_SIZE_Y, 2000, false))
		return (UNKNOWN);
	ft_rm_space(&line);
	if (*line != '\0')
		return (ft_perror_end(line));
	return (WIN_SIZE);
}
