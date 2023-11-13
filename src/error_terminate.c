/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_terminate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:17:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 14:31:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_error.h"

void	ft_terminate(void)
{
	exit(1);
}

void	ft_perror(char *msg, int save_errno)
{
	ft_putendl_fd("Error", 2);
	if (!save_errno)
		ft_putendl_fd(msg, 2);
	else
	{
		errno = save_errno;
		perror(msg);
	}
}
