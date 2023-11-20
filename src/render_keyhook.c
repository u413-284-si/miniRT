/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 15:24:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_key_hook_press(int key, t_render *render)
{
	if (key == KEY_ESC)
		mlx_loop_end(render->mlx_ptr);
	return (0);
}