/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:48:32 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/06 21:04:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_mouse_hook_press(int button, int x, int y, t_engine *engine)
{
	if (button == M_LEFT)
	{
		engine->mouse.left = true;
		engine->mouse.last_left[X] = x;
		engine->mouse.last_left[Y] = y;
	}
	else if (button == M_RIGHT)
	{
		engine->mouse.right = true;
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
		engine->mouse.left = false;
	if (button == M_RIGHT)
		engine->mouse.right = false;
	mlx_mouse_show(engine->render.mlx_ptr, engine->render.win_ptr);
	return (0);
}

int	ft_mouse_hook_move(int x, int y, t_engine *engine)
{
	if (x > engine->image.image_width || x < 0
		|| y > engine->image.image_height || y < 0)
		return (0);
	if (engine->mouse.right)
	{
		//ft_mouse_translate(x, y, engine);
		ft_mouse_move_center(engine);
	}
	return (0);
}

void	ft_mouse_move_center(t_engine *engine)
{
	int	x;
	int	y;

	x = engine->image.image_width * 0.5;
	y = engine->image.image_height * 0.5;
	mlx_mouse_move(engine->render.mlx_ptr, engine->render.win_ptr, x, y);
}

/*
void	ft_mouse_translate(int x, int y, t_engine *engine)
{
	int		delta_x;
	int		delta_y;
	float	distance;

	delta_x = engine->mouse.last_right[X] - x;
	delta_y = engine->mouse.last_right[Y] - y;
	distance = sqrt(delta_x * delta_x + delta_y * delta_y);
	if (distance < 10)
		return ;
	engine->map.props.translate[X] -= delta_x;
	if (engine->map.props.translate[X] >= 5000
		|| engine->map.props.translate[X] <= -5000)
		engine->map.props.translate[X] += delta_x;
	else
		engine->map.mat[3][0] -= delta_x;
	engine->map.props.translate[Y] -= delta_y;
	if (engine->map.props.translate[Y] >= 5000
		|| engine->map.props.translate[Y] <= -5000)
		engine->map.props.translate[Y] += delta_y;
	else
		engine->map.mat[3][1] -= delta_y;
	engine->mouse.last_right[X] = x;
	engine->mouse.last_right[Y] = y;
}
*/