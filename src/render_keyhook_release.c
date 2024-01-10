/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_release.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:42:02 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 13:25:51 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_keyhook_release(int key, t_render *render)
{
	if (key == XK_p)
	{
		mlx_do_key_autorepeatoff(render->mlx_ptrs.mlx_ptr);
		render->is_printing = true;
	}
	return (0);
}
