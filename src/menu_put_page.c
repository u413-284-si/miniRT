/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:16:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 13:43:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_put_page_scene(t_putinfo put, t_hittable active, t_pages cur_page)
{
	if (cur_page == PAGE_SCENE)
		ft_put_hittable(put, active);
	else
		ft_put_ctrl_hittable(put, active);
}

void	ft_put_page_ambient(t_putinfo put, t_light ambient, t_pages cur_page)
{
	if (cur_page == PAGE_LIGHT)
		ft_put_ambient(put, ambient);
	else
		ft_put_ctrl_light(put, 0);
}

void	ft_put_page_light(t_putinfo put, t_light light, t_pages cur_page)
{
	if (cur_page == PAGE_LIGHT)
		ft_put_light(put, light);
	else
		ft_put_ctrl_light(put, light.id);
}

void	ft_put_page_cam(t_putinfo put, t_cam cam, t_pages cur_page)
{
	if (cur_page == PAGE_CAM)
		ft_put_cam(put, cam);
	else
		ft_put_ctrl_cam(put);
}
