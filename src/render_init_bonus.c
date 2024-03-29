/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:21:18 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 10:19:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

t_err	ft_render_init(t_render *render)
{
	if (ft_init_mlx_ptrs(&render->mlx_ptrs, &render->win_size))
		return (ERROR);
	if (ft_cam_init(&render->cam, render->mlx_ptrs.img.size))
		return (ERROR);
	if (ft_err_malloc((void **)&render->sample_buffer,
			sizeof(*render->sample_buffer)
			* render->cam.image.x * render->cam.image.y))
		return (ERROR);
	ft_menu_init(&render->menu, MENU_OPACITY, MENU_BACK, MENU_FONT);
	if (render->scene.total == 0)
		render->active_hittable = -1;
	ft_option_set(&render->options, O_MODE_SCENE);
	ft_option_set(&render->options, O_SCENE_CHANGED);
	ft_option_set(&render->options, O_MANIP_LOW);
	ft_option_set(&render->options, O_IS_THREADED);
	ft_option_set(&render->options, O_IS_ANTI_ALIAS);
	render->sample_goal = SAMPLE_SIZE;
	render->mut_print = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	srand(time(0));
	return (SUCCESS);
}
