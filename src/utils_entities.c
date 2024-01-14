/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:53:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/23 21:54:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	ft_cy_calc_caps(t_cylinder *cy)
{
	cy->cap1 = ft_vec3_add(cy->centre, ft_vec3_scale(cy->axis, -cy->h / 2.0));
	cy->cap2 = ft_vec3_add(cy->centre, ft_vec3_scale(cy->axis, cy->h / 2.0));
}
