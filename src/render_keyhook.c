/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/19 22:49:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_keyhook_press(int key, t_render *render)
{
	static bool	print;

	if (key == K_ESC)
		mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	else if (key == K_C && !print)
	{
		print = true;
		ft_output_as_ppm((int *)render->mlx_ptrs.img.addr, render->image.image_width, render->image.image_height);
		print = false;
	}
	return (0);
}
