/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:18:52 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 16:58:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_move_cam_forward(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam->direction, dist));
}

void	ft_move_cam_up(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam->vup, dist));
}

void	ft_move_cam_right(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam->right, dist));
}

void	ft_rotate_cam(t_cam *cam, int delta[2])
{
	//t_quat	rotate_pitch;
	//t_quat	rotate_yaw;
	//t_quat	q;

	//float pitch = delta[1] * 0.002;
	//float yaw = delta[0] * 0.3;
	//rotate_pitch = ft_quat_angle_axis(-pitch, cam->right);
	//rotate_yaw = ft_quat_angle_axis(-yaw, cam->vup);
	//q = ft_quat_norm(ft_quat_mult(rotate_pitch, rotate_yaw));
	//cam->direction = ft_quat_rotate2(yaw, cam->vup, cam->direction);
	(void)cam;
	(void)delta;
}
