/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:49:48 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 11:50:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_move_camera(int key, t_cam *cam)
{
	if (key == KEY_Q)
		ft_cam_move_vertical(cam, -MV_UNIT);
	else if (key == KEY_E)
		ft_cam_move_vertical(cam, MV_UNIT);
	else if (key == KEY_W)
		ft_cam_move_horizontal(cam, MV_UNIT);
	else if (key == KEY_S)
		ft_cam_move_horizontal(cam, -MV_UNIT);
	else if (key == KEY_A)
		ft_cam_move_lateral(cam, -MV_UNIT);
	else if (key == KEY_D)
		ft_cam_move_lateral(cam, MV_UNIT);
	ft_cam_update_view(cam, false);
}

void	ft_pan_camera(int key, t_cam *cam)
{
	if (key == KEY_ARROW_UP)
		cam->pitch += MV_UNIT;
	else if (key == KEY_ARROW_DOWN)
		cam->pitch -= MV_UNIT;
	else if (key == KEY_ARROW_LEFT)
		cam->yaw -= MV_UNIT;
	else if (key == KEY_ARROW_RIGHT)
		cam->yaw += MV_UNIT;
	ft_cam_update_view(cam, true);
}
