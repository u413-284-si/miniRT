/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/17 15:20:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"



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
	else if (key == KEY_ONE || key == KEY_TWO)
		ft_change_active_hittable(key, &engine->scene);
	else if (key == KEY_Q || key == KEY_E || key == KEY_W || key == KEY_A
		|| key == KEY_S || key == KEY_D || key == KEY_R || key == KEY_F
		|| key ==  KEY_ARROW_RIGHT || key == KEY_ARROW_LEFT)
		ft_manip_hittable(key, &engine->scene);
	return (0);
}
