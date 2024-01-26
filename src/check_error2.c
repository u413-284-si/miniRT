/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:25:15 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/18 09:28:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

bool	ft_perror_not_unit(char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("No possible unit vector: -->", 2);
	ft_putendl_fd(line, 2);
	ft_putendl_fd("Expected: Not the zero vector {0,0,0}", 2);
	return (false);
}

void	ft_pwarning_not_unit(char *line)
{
	ft_putendl_fd("Warning", 2);
	ft_putstr_fd("Not a unit vector: -->", 2);
	ft_putendl_fd(line, 2);
	ft_putendl_fd("Vector was successfully normalized.", 2);
}
