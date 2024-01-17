/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:13:48 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/17 16:53:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_err	ft_render_init(t_render *render)
{
	if (ft_init_mlx_ptrs(&render->mlx_ptrs, false))
		return (ERROR);
	if (ft_cam_init(&render->cam, render->mlx_ptrs.img.size))
	{
		ft_free_mlx(&render->mlx_ptrs);
		return (ERROR);
	}
	ft_menu_init(&render->menu, MENU_OPACITY, MENU_BACK, MENU_FONT);
	mlx_set_font(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr, REGULAR);
	render->is_changed = true;
	render->is_threaded = true;
	render->mut_print = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (SUCCESS);
}
