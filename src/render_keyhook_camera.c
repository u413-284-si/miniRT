/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:43:17 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/24 22:56:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_manip_cam(int key, t_cam *cam)
{
	if (key == XK_q)
		ft_cam_move_up(cam, -MV_UNIT);
	else if (key == XK_e)
		ft_cam_move_up(cam, MV_UNIT);
	else if (key == XK_w)
		ft_cam_move_forward(cam, MV_UNIT);
	else if (key == XK_s)
		ft_cam_move_forward(cam, -MV_UNIT);
	else if (key == XK_d)
		ft_cam_move_right(cam, MV_UNIT);
	else if (key == XK_a)
		ft_cam_move_right(cam, -MV_UNIT);
}
