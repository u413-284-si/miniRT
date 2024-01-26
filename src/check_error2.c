/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:25:15 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 18:10:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

bool	ft_perror_not_unit(char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("No possible unit vector: -->", 2);
	ft_putendl_fd(line, 2);
	ft_putendl_fd(MSG_EXP_UNIT, 2);
	return (false);
}

void	ft_pwarning_not_unit(char *line)
{
	ft_putendl_fd("Warning", 2);
	ft_putstr_fd("Not a unit vector: -->", 2);
	ft_putendl_fd(line, 2);
	ft_putendl_fd("Vector was successfully normalized.", 2);
}

void	ft_pinfo_line_number(int line_num)
{
	ft_putstr_fd("Line number [ignoring empty lines]", 2);
	ft_putstr_fd(": <", 2);
	ft_putnbr_fd(line_num, 2);
	ft_putendl_fd(">", 2);
}
