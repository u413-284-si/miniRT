/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:10:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/18 09:10:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_rm_space(char **str)
{
	char	*begin;
	char	*end;

	if (**str == ' ')
		(*str)++;
	else if (**str == '\t')
	{
		(*str)++;
		*(*str - 1) = ' ';
	}
	begin = *str;
	end = *str;
	while (*end == ' ' || *end == '\t')
		end++;
	if (begin == end)
		return ;
	while (*end)
		*begin++ = *end++;
	*begin = '\0';
}
