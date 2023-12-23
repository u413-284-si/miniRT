/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:19:33 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/23 21:41:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_keyhook_mv_point(int key, t_vec3 *point)
{
	if (key == XK_q)
		point->z -= MV_UNIT;
	else if (key == XK_e)
		point->z += MV_UNIT;
	else if (key == XK_w)
		point->y += MV_UNIT;
	else if (key == XK_s)
		point->y -= MV_UNIT;
	else if (key == XK_d)
		point->x += MV_UNIT;
	else if (key == XK_a)
		point->x -= MV_UNIT;
}

void	ft_keyhook_rot_vec(int key, t_vec3 *vector)
{
	if (key == XK_Left)
		*vector = ft_vec3_rotate_x(*vector, MV_UNIT);
	else if (key == XK_Right)
		*vector = ft_vec3_rotate_x(*vector, -MV_UNIT);
	else if (key == XK_Up)
		*vector = ft_vec3_rotate_y(*vector, MV_UNIT);
	else if (key == XK_Down)
		*vector = ft_vec3_rotate_y(*vector, -MV_UNIT);
}
