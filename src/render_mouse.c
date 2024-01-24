/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:30:26 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/24 11:39:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_mouse_hook_press(int button, int x, int y, t_render *render)
{
	if (button == Button3)
	{
		render->mouse.right = true;
		render->mouse.last_pos.x = x;
		render->mouse.last_pos.y = y;
	}
	return (0);
}

int	ft_mouse_hook_release(int button, int x, int y, t_render *render)
{
	(void)x;
	(void)y;
	if (button == Button1)
		render->mouse.left = !render->mouse.left;
	if (button == Button3)
		render->mouse.right = false;
	return (0);
}

int	ft_mouse_hook_move(int x, int y, t_render *render)
{
	if (x > render->mlx_ptrs.img.size.x || x < 0
		|| y > render->mlx_ptrs.img.size.y || y < 0)
		return (0);
	if (render->mouse.right)
	{
		ft_mouse_hook_rot_cam(x, y, render);
	}
	return (0);
}

void	ft_mouse_hook_rot_cam(int x, int y, t_render *render)
{
	t_vec2f	delta;

	delta.x = (render->mouse.last_pos.x - x) * 0.001;
	delta.y = (render->mouse.last_pos.y - y) * 0.001;
	if (delta.x != 0)
		render->cam.direction = ft_vec3_rotate_y(render->cam.direction,
				delta.x);
	if (delta.y != 0)
		render->cam.direction = ft_vec3_rotate_x(render->cam.direction,
				delta.y);
	render->mouse.last_pos.x = x;
	render->mouse.last_pos.y = y;
	ft_cam_calc_base_vectors(&render->cam);
	ft_cam_calc_pixel_grid(&render->cam);
	ft_cam_calc_pix_pos(&render->cam);
	ft_option_set(&render->options, O_SCENE_CHANGED);
}
