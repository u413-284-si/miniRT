/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_general_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:54:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/13 10:53:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

t_vec2i	ft_put_mode(t_putinfo put, uint32_t options)
{
	mlx_set_font(put.mlx_ptrs.mlx_ptr, put.mlx_ptrs.win_ptr, BOLD);
	ft_put_str(put, "Mode:");
	put.pos.x += 50;
	if (ft_option_isset(options, O_MODE_SCENE))
		ft_put_str(put, "Scene");
	else if (ft_option_isset(options, O_MODE_LIGHT))
		ft_put_str(put, "Light");
	else if (ft_option_isset(options, O_MODE_CAM))
		ft_put_str(put, "Camera");
	mlx_set_font(put.mlx_ptrs.mlx_ptr, put.mlx_ptrs.win_ptr, REGULAR);
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}

t_vec2i	ft_put_type(t_putinfo put, t_type type)
{
	ft_put_str(put, "Type:");
	put.pos.x += 50;
	if (type == SPHERE)
		ft_put_str(put, "Sphere");
	else if (type == PLANE)
		ft_put_str(put, "Plane");
	else if (type == CYLINDER)
		ft_put_str(put, "Cylinder");
	else if (type == AMBIENT)
		ft_put_str(put, "Ambient");
	else if (type == LIGHT)
		ft_put_str(put, "Light");
	put.pos.x -= 50;
	put.pos.y += Y_NEXT_LINE_BIG;
	return (put.pos);
}

t_vec2i	ft_put_id(t_putinfo put, int id, int total)
{
	ft_put_str(put, "Active ID:");
	put.pos.x += 90;
	ft_put_int(put, (t_numinfo){.numi = id, .pad = 0, .prec = 0});
	put.pos.x += (ft_numlen(id) * 10);
	ft_put_str(put, " / ");
	put.pos.x += 30;
	ft_put_int(put, (t_numinfo){.numi = total, .pad = 0, .prec = 0});
	put.pos.x -= 120 + (ft_numlen(id) * 10);
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}

t_vec2i	ft_put_inc(t_putinfo put, uint32_t options)
{
	t_numinfo	num;

	num = (t_numinfo){.numf = 0.0, .pad = 0, .prec = 2};
	if (ft_option_isset(options, O_MANIP_LOW))
		num.numf = INC_LOW;
	else if (ft_option_isset(options, O_MANIP_MID))
		num.numf = INC_MID;
	else if (ft_option_isset(options, O_MANIP_HIGH))
		num.numf = INC_HIGH;
	ft_put_str(put, "Inc:");
	put.pos.x += 40;
	ft_put_float(put, num);
	put.pos.x -= 40;
	put.pos.y += Y_NEXT_LINE;
	return (put.pos);
}
