/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:18:52 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/27 10:23:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_move_cam_w(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam->w, dist));
}

void	ft_move_cam_up(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam->vup, dist));
}

void	ft_move_cam_u(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam->u, dist));
}

void	ft_rotate_cam(t_cam *cam, float angle, float x, float y, float z)
{
	t_quat	temp;
	t_quat	quat_view;
	t_quat	result;

	temp.x = x * sin(angle/2);
	temp.y = y * sin(angle/2);
	temp.z = z * sin(angle/2);
	temp.w = cos(angle/2);
	quat_view.x = cam->look_at.x;
	quat_view.y = cam->look_at.y;
	quat_view.z = cam->look_at.z;
	quat_view.w = 0;
	result = ft_quat_mult(ft_quat_mult(temp, quat_view), ft_quat_conjugate(temp));
	cam->look_at.x = result.x;
	cam->look_at.y = result.y;
	cam->look_at.z = result.z;
}
