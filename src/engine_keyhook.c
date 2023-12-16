/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 10:20:46 by gwolf            ###   ########.fr       */
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
	ft_cam_update(cam, false);
}

void	ft_pan_camera(int key, t_cam *cam)
{
	if (key == KEY_ARROW_UP)
		cam->pitch += 0.03;
	else if (key == KEY_ARROW_DOWN)
		cam->pitch -= 0.03;
	else if (key == KEY_ARROW_LEFT)
		cam->yaw += 0.03;
	else if (key == KEY_ARROW_RIGHT)
		cam->yaw -= 0.03;
	ft_cam_update(cam, true);
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
	if (key == KEY_Q)
		sp->centre.z -= MV_UNIT;
	else if (key == KEY_E)
		sp->centre.z += MV_UNIT;
	else if (key == KEY_W)
		sp->centre.y += MV_UNIT;
	else if (key == KEY_S)
		sp->centre.y -= MV_UNIT;
	else if (key == KEY_D)
		sp->centre.x -= MV_UNIT;
	else if (key == KEY_A)
		sp->centre.x += MV_UNIT;
	else if (key == KEY_R)
		sp->r -= MV_UNIT;
	else if (key == KEY_F)
		sp->r += MV_UNIT;
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
		print = false;
	}
	else if ((engine->mouse.right == true) && (key == KEY_Q || key == KEY_E
			|| key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D))
		ft_move_camera(key, &engine->cam);
	else if ((engine->mouse.right == true) && (key == KEY_ARROW_DOWN
			|| key == KEY_ARROW_UP || key == KEY_ARROW_LEFT
			|| key == KEY_ARROW_RIGHT))
		ft_pan_camera(key, &engine->cam);
	else if (key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT)
		ft_change_active_hittable(key, &engine->scene);
	else if (key == KEY_Q || key == KEY_E || key == KEY_W || key == KEY_A
		|| key == KEY_S || key == KEY_D || key == KEY_R || key == KEY_F)
		ft_manip_hittable(key, &engine->scene);
	return (0);
}
