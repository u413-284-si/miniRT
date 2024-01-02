/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 19:59:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_keyhook_press(int key, t_render *render)
{
	static bool	print;

	if (key == XK_Escape)
		mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	else if (key == XK_c && !print)
	{
		print = true;
		ft_output_as_ppm((int *)render->mlx_ptrs.img.addr,
			render->mlx_ptrs.img.size.x, render->mlx_ptrs.img.size.y);
		print = false;
	}
	else if (key == XK_n || key == XK_m)
		ft_change_active_hittable(key, &render->scene);
	else if ((render->mouse.left)
		&& (key == XK_w || key == XK_s || key == XK_a || key == XK_d
			|| key == XK_q || key == XK_e || key == XK_r || key == XK_f
			|| (key >= XK_Left && key <= XK_Down)))
		ft_manip_cam(key, &render->cam);
	else if (key == XK_w || key == XK_s || key == XK_a || key == XK_d
		|| key == XK_q || key == XK_e || key == XK_r || key == XK_f
		|| key == XK_t || key == XK_g
		|| (key >= XK_Left && key <= XK_Down)
		|| (key >= XK_0 && key <= XK_9))
		ft_manip_hittable(key, &render->scene.obj[render->scene.active]);
	return (0);
}
