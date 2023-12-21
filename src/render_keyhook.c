/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/22 00:55:41 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_keyhook_press(int key, t_render *render)
{
	static bool	print;

	if (key == XK_Escape)
		mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	else if (key == XK_c && !print)
	{
		print = true;
		ft_output_as_ppm((int *)render->mlx_ptrs.img.addr,
				render->mlx_ptrs.img.width, render->mlx_ptrs.img.height);
		print = false;
	}
	return (0);
}
