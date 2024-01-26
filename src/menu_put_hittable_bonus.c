/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_hittable_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:49:29 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/22 16:55:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_put_hittable(t_putinfo put, t_hittable hittable, int total)
{
	put.pos = ft_put_id(put, hittable.id, total);
	put.pos = ft_put_type(put, hittable.type);
	if (hittable.type == SPHERE)
		ft_put_sp(put, hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_put_pl(put, hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_put_cy(put, hittable.params.cy);
	else if (hittable.type == CONE)
		ft_put_co(put, hittable.params.co);
}


void	ft_put_co(t_putinfo put, t_cone co)
{
	put.pos = ft_put_3d_point("Apex", put, co.apex);
	put.pos = ft_put_unit_vec("Axis", put, co.axis);
	put.pos = ft_put_single_float_value("Diameter", put, co.r * 2);
	put.pos = ft_put_single_float_value("Height", put, co.h);
	put.pos = ft_put_colour(put, co.colour);
}

