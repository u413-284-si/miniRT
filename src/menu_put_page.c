/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:16:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 18:26:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_put_main_page(t_putinfo put, t_render *render)
{
	if (ft_option_isset(render->options, O_MODE_SCENE))
		ft_put_page_scene(put, render->scene.obj[render->active_hittable],
			render->scene.total, render->options);
	else if (ft_option_isset(render->options, O_MODE_LIGHT))
	{
		if (render->active_light == 0)
			ft_put_page_light(put, render->scene.ambient,
				render->scene.lsrc_count, render->options);
		else
			ft_put_page_light(put, render->scene.lsrc[render->active_light - 1],
				render->scene.lsrc_count, render->options);
	}
	else if (ft_option_isset(render->options, O_MODE_CAM))
		ft_put_page_cam(put, render->cam, render->options);
}

void	ft_put_page_scene(t_putinfo put, t_hittable active, int total, \
	uint32_t options)
{
	if (!ft_option_isset(options, O_SHOW_CTRL))
		ft_put_hittable(put, active, total);
	else
		ft_put_ctrl_hittable(put, active.type);
}

void	ft_put_page_light(t_putinfo put, t_light light, int total, \
	uint32_t options)
{
	if (!ft_option_isset(options, O_SHOW_CTRL))
		ft_put_light(put, light, total);
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
