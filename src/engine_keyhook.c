/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/08 01:36:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_move_camera(int key, t_cam *cam)
{
	if (key == KEY_Q)
		ft_move_cam_up(cam, -MV_UNIT);
	else if (key == KEY_E)
		ft_move_cam_up(cam, MV_UNIT);
	else if (key == KEY_W)
		ft_move_cam_forward(cam, MV_UNIT);
	else if (key == KEY_S)
		ft_move_cam_forward(cam, -MV_UNIT);
	else if (key == KEY_A)
		ft_move_cam_right(cam, -MV_UNIT);
	else if (key == KEY_D)
		ft_move_cam_right(cam, MV_UNIT);
	ft_cam_update(cam);
}

void	ft_change_active_hittable(int key, t_entities *scene)
{
	if (scene->active == -1)
		return ;
	if (key == KEY_ARROW_LEFT)
	{
		scene->active--;
		if (scene->active < 0)
			scene->active = scene->total - 1;
	}
	if (key == KEY_ARROW_RIGHT)
	{
		scene->active++;
		if (scene->active == scene->total)
			scene->active = 0;
	}
}

void	ft_manip_sphere(int key, t_sphere *sp)
{
	if (key == KEY_Z)
		sp->centre.z -= 1;
	else if (key == KEY_I)
		sp->centre.z += 1;
	if (key == KEY_U)
		sp->centre.y -= 1;
	else if (key == KEY_J)
		sp->centre.y += 1;
	if (key == KEY_H)
		sp->centre.x -= 1;
	else if (key == KEY_K)
		sp->centre.x += 1;
	if (key == KEY_N)
		sp->r -= 1;
	else if (key == KEY_M)
		sp->r += 1;
}

void	ft_manip_hittable(int key, t_entities *scene)
{
	if (scene->obj[scene->active].type == SPHERE)
		ft_manip_sphere(key, &scene->obj[scene->active].params.sp);
}

int	ft_keyhook_press(int key, t_engine *engine)
{
	static bool	print;

	if (key == KEY_ESC)
		mlx_loop_end(engine->render.mlx_ptr);
	else if (key == KEY_C && !print)
	{
		print = true;
		ft_output_as_ppm((int *)engine->render.buffer.addr, 800, 450);
	}
	else if (key == KEY_Q || key == KEY_W || key == KEY_E || key == KEY_A
		|| key == KEY_S || key == KEY_D)
	{
		ft_move_camera(key, &engine->cam);
	}
	else if (key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT)
		ft_change_active_hittable(key, &engine->scene);
	else if (key == KEY_Z || key == KEY_U || key == KEY_I || key == KEY_H
		|| key == KEY_J || key == KEY_K || key == KEY_N || key == KEY_M)
		ft_manip_hittable(key, &engine->scene);
	return (0);
}
