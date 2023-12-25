/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:30:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 08:49:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_mouse_hook_press(int button, int x, int y, t_render *render)
{
	if (button == Button1)
	{
		render->mouse.left = true;
		render->mouse.last_left.x = x;
		render->mouse.last_left.y = y;
	}
	else if (button == Button3)
	{
		render->mouse.right = true;
		render->mouse.last_right.x = x;
		render->mouse.last_right.y = y;
	}
	return (0);
}

int	ft_mouse_hook_release(int button, int x, int y, t_render *render)
{
	(void)x;
	(void)y;
	if (button == Button1)
		render->mouse.left = false;
	if (button == Button3)
		render->mouse.right = false;
	return (0);
}

int	ft_mouse_hook_move(int x, int y, t_render *render)
{
	if (x > render->mlx_ptrs.img.size.x || x < 0
		|| y > render->mlx_ptrs.img.size.y || y < 0)
		return (0);
	if (render->mouse.right)
	{
		;
	}
	return (0);
}
