/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/31 11:46:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

bool	ft_is_manip_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d
		|| key == XK_q || key == XK_e || key == XK_r || key == XK_f
		|| key == XK_t || key == XK_g || key == XK_n || key == XK_m
		|| (key >= XK_Left && key <= XK_Down)
		|| (key >= XK_0 && key <= XK_9));
}

void	ft_manip_scene(int key, t_entities *scene)
{
	if (key == XK_n || key == XK_m)
		ft_change_active_hittable(key, scene);
	else
		ft_manip_hittable(key, &scene->obj[scene->active]);

}

void	ft_change_mode(t_render *render)
{
	if (render->mode == CTRL_SCENE)
		render->mode = CTRL_CAM;
	else if (render->mode == CTRL_CAM)
		render->mode = CTRL_LIGHT;
	else if (render->mode == CTRL_LIGHT)
		render->mode = CTRL_SCENE;
}

int	ft_keyhook_press(int key, t_render *render)
{
	static bool	print;

	if (key == XK_Escape)
		mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	else if (key == XK_c && !print)
	{
		print = true;
		ft_output_as_ppm((int *)render->mlx_ptrs.img.addr,
			render->mlx_ptrs.img.width, render->mlx_ptrs.img.height);
		print = false;
	}
	else if (key == XK_i)
		render->show_menu = !render->show_menu;
	else if (key == XK_Control_L)
		ft_change_mode(render);
	else if (ft_is_manip_key(key))
	{
		if (render->mode == CTRL_SCENE)
			ft_manip_scene(key, &render->scene);
		else if (render->mode == CTRL_CAM)
			;//ft_manip_camera(key, &render->cam);
		else if (render->mode == CTRL_LIGHT)
			ft_manip_light(key, &render->scene);
	}
	return (0);
}
