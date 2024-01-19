/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_release.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 17:20:22 by sqiu             ###   ########.fr       */
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
