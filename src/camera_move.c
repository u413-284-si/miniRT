/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:18:52 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 10:11:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_move_cam_forward(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(ft_vec3_norm(cam->look_at), dist));
}

void	ft_move_cam_up(t_cam *cam, float dist)
{
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale((t_vec3){0, 1, 0}, dist));
}

void	ft_move_cam_right(t_cam *cam, float dist)
{
	t_vec3	cam_right;

	cam_right = ft_vec3_norm(ft_vec3_cross(cam->look_at, (t_vec3){0, 1, 0}));
	cam->look_from = ft_vec3_add(cam->look_from, ft_vec3_scale(cam_right, dist));
}

void	ft_rotate_cam(t_cam *cam, int delta[2])
{
	t_vec3	direction;

	cam->yaw += delta[0] * 0.002;
	cam->pitch += delta[1] * 0.002;

	if (cam->pitch > 1.5f)
		cam->pitch = 1.5f;
	if (cam->pitch < -1.5f)
		cam->pitch = -1.5f;

	direction.x = cos(cam->yaw) * cos(cam->pitch);
	direction.y = sin(cam->pitch);
	direction.z = sin(cam->yaw) * cos(cam->pitch);
	cam->look_at = ft_vec3_norm(direction);
	printf("Look at: x %.2f, y %.2f, z %.2f\n)", cam->look_at.x, cam->look_at.y, cam->look_at.z);
	printf("Pitch: %.2f, Yaw: %.2f\n", cam->pitch, cam->yaw);
}
