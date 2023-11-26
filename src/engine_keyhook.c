/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/26 10:18:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_move_camera(int key, t_cam *cam, t_viewport *vp, t_image *image)
{
	if (key == KEY_Q)
		cam->look_from.z += 1;
	else if (key == KEY_E)
		cam->look_from.z -= 1;
	else if (key == KEY_W)
		cam->look_from.y += 1;
	else if (key == KEY_S)
		cam->look_from.y -= 1;
	else if (key == KEY_A)
		cam->look_from.x += 1;
	else if (key == KEY_D)
		cam->look_from.x -= 1;
	ft_initiate_camera(cam);
	ft_initiate_viewport(vp, *cam, *image);
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
		ft_move_camera(key, &engine->cam, &engine->vp, &engine->image);
	}
	return (0);
}
