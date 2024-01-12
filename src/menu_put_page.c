/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:16:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/12 19:04:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_put_main_page(t_putinfo put, t_render *render)
{
	if (ft_option_isset(render->options, O_MODE_SCENE))
		ft_put_page_scene(put, render->scene.obj[render->active_hittable],
			render->options);
	else if (ft_option_isset(render->options, O_MODE_LIGHT))
	{
		if (render->active_light == 0)
			ft_put_page_ambient(put, render->scene.ambient, render->options);
		else
			ft_put_page_light(put, render->scene.lsrc[render->active_light - 1],
				render->options);
	}
	else if (ft_option_isset(render->options, O_MODE_CAM))
		ft_put_page_cam(put, render->cam, render->options);
}

void	ft_put_page_scene(t_putinfo put, t_hittable active, uint32_t options)
{
	if (!ft_option_isset(options, O_SHOW_CTRL))
		ft_put_hittable(put, active);
	else
		ft_put_ctrl_hittable(put, active);
}

void	ft_put_page_ambient(t_putinfo put, t_light ambient, uint32_t options)
{
	if (!ft_option_isset(options, O_SHOW_CTRL))
		ft_put_ambient(put, ambient);
	else
		ft_put_ctrl_light(put, 0);
}

void	ft_put_page_light(t_putinfo put, t_light light, uint32_t options)
{
	if (!ft_option_isset(options, O_SHOW_CTRL))
		ft_put_light(put, light);
	else
		ft_put_ctrl_light(put, light.id);
}

void	ft_put_page_cam(t_putinfo put, t_cam cam, uint32_t options)
{
	if (!ft_option_isset(options, O_SHOW_CTRL))
		ft_put_cam(put, cam);
	else
		ft_put_ctrl_cam(put);
}
