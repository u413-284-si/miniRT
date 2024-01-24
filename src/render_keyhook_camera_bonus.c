/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_camera_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:43:17 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/24 11:46:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ft_manip_cam(int key, t_cam *cam, float inc, uint32_t *options)
{
	if (key == XK_r || key == XK_f)
	{
		ft_keyhook_fov_cam(key, cam, inc);
		ft_cam_calc_viewport_dimensions(cam);
	}
	else if (key >= XK_Left && key <= XK_Down)
	{
		ft_keyhook_rot_cam(key, &cam->direction, inc);
		ft_cam_calc_base_vectors(cam);
	}
	else
		ft_keyhook_move_cam(key, cam, inc);
	ft_cam_calc_pixel_grid(cam);
	if (ft_option_isset(*options, O_IS_THREADED))
	{
		if (ft_spin_threads(cam, ft_cam_calc_pix_pos_threaded))
			ft_option_clear(options, O_IS_THREADED);
	}
	else
		ft_cam_calc_pix_pos(cam);
	ft_option_set(options, O_SCENE_CHANGED);
}
