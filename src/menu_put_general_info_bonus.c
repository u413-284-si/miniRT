/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_general_info_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:04 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/23 13:49:27 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_type(t_putinfo put, t_type type)
{
	ft_put_str(put, "Type:");
	put.pos.x += 70;
	if (type == SPHERE)
		ft_put_str(put, "Sphere");
	else if (type == PLANE)
		ft_put_str(put, "Plane");
	else if (type == CYLINDER)
		ft_put_str(put, "Cylinder");
	else if (type == CONE)
		ft_put_str(put, "Cone");
	else if (type == AMBIENT)
		ft_put_str(put, "Ambient");
	else if (type == LIGHT)
		ft_put_str(put, "Light");
	put.pos.x -= 70;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}
