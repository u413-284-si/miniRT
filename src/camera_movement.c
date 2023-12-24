/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:38:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/24 22:55:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_cam_move_forward(t_cam *cam, float distance)
{
	cam->position = ft_vec3_add(cam->position, ft_vec3_scale(cam->w, distance));
}

void	ft_cam_move_right(t_cam *cam, float distance)
{
	cam->position = ft_vec3_add(cam->position, ft_vec3_scale(cam->u, distance));
}

void	ft_cam_move_up(t_cam *cam, float distance)
{
	const t_vec3	world_up = {0.0, 1.0, 0.0};

	cam->position = ft_vec3_add(cam->position, ft_vec3_scale(world_up, distance));
}
