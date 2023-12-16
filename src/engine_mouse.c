/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:48:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 10:10:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_mouse_hook_press(int button, int x, int y, t_engine *engine)
{
	if (button == M_LEFT)
	{
		//engine->mouse.left = true;
		engine->mouse.last_left[X] = x;
		engine->mouse.last_left[Y] = y;
	}
	else if (button == M_RIGHT)
	{
		//engine->mouse.right = true;
		engine->mouse.last_right[X] = x;
		engine->mouse.last_right[Y] = y;
		mlx_mouse_hide(engine->render.mlx_ptr, engine->render.win_ptr);
		ft_mouse_move_center(engine);
	}
	return (0);
}

int	ft_mouse_hook_release(int button, int x, int y, t_engine *engine)
{
	(void)x;
	(void)y;
	if (button == M_LEFT)
		engine->mouse.left = !engine->mouse.left;
	if (button == M_RIGHT)
		engine->mouse.right = !engine->mouse.right;
	mlx_mouse_show(engine->render.mlx_ptr, engine->render.win_ptr);
	return (0);
}

int	ft_mouse_hook_move(int x, int y, t_engine *engine)
{
	int	delta[2];
	static bool	first;

	if (!first)
	{
		engine->mouse.last_right[0] = x;
		engine->mouse.last_right[1] = y;
		first = true;
	}

	if (x > engine->image.width || x < 0
		|| y > engine->image.height || y < 0)
		return (0);
	if (engine->mouse.right)
	{
		ft_mouse_calc_delta(x, y, engine, delta);
		if (delta[X] > 0.0 && delta[Y] > 0.0)
		{
			ft_rotate_cam(&engine->cam, delta);
			ft_cam_update(&engine->cam, true);
		}
		ft_mouse_move_center(engine);
	}
	return (0);
}

void	ft_mouse_move_center(t_engine *engine)
{
	int	x;
	int	y;

	x = engine->image.width * 0.5;
	y = engine->image.height * 0.5;
	mlx_mouse_move(engine->render.mlx_ptr, engine->render.win_ptr, x, y);
}


void	ft_mouse_calc_delta(int x, int y, t_engine *engine, int delta[2])
{
	delta[X] = engine->mouse.last_right[X] - x;
	delta[Y] = y - engine->mouse.last_right[Y];
	engine->mouse.last_right[X] = x;
	engine->mouse.last_right[Y] = y;
}
