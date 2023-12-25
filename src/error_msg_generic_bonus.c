/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_generic_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:17:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 13:39:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_msg_bonus.h"

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

void	ft_perror_number(char *msg, int number)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": <", 2);
	ft_putnbr_fd(number, 2);
	ft_putendl_fd(">", 2);
}
