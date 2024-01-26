/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:28 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 14:40:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

void	ft_perror_count(t_type type, int max, int count, bool high)
{
	static const char	*entity_name[SUM_ENTS] = {
	[SPHERE] = "sphere (sp)",
	[PLANE] = "plane (pl)",
	[CYLINDER] = "cylinder (cy)",
	[CONE] = "cone (co)",
	[AMBIENT] = "ambient light (A)",
	[CAMERA] = "camera (C)",
	[LIGHT] = "light (L)"
	};

	ft_putendl_fd("Error", 2);
	if (high)
		ft_putstr_fd("Too many entities of type <", 2);
	else
		ft_putstr_fd("Missing entity of type <", 2);
	ft_putstr_fd((char *)entity_name[type], 2);
	ft_putendl_fd(">", 2);
	if (!high)
		return ;
	ft_putstr_fd("Expected: ", 2);
	ft_putnbr_fd(max, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("But got:  ", 2);
	ft_putnbr_fd(count, 2);
	ft_putendl_fd("", 2);
}
