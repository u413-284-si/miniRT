/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:19:33 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 19:22:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_keyhook_inc_dec(int key, float *value, float max)
{
	if (key == XK_r || key == XK_t)
	{
		*value -= MV_UNIT;
		if (*value < 0)
			*value = 0;
	}
	else if (key == XK_f || key == XK_g)
	{
		*value += MV_UNIT;
		if (*value > max)
			*value = max;
	}
}

void	ft_keyhook_mv_point(int key, t_vec3 *point)
{
	const t_interval	lim = (t_interval){.min = FLOAT_MIN, .max = FLOAT_MAX};

	if (key == XK_e && point->z < lim.max)
		point->z += MV_UNIT;
	else if (key == XK_q && point->z > lim.min)
		point->z -= MV_UNIT;
	else if (key == XK_w && point->y < lim.max)
		point->y += MV_UNIT;
	else if (key == XK_s && point->y > lim.min)
		point->y -= MV_UNIT;
	else if (key == XK_d && point->x < lim.max)
		point->x += MV_UNIT;
	else if (key == XK_a && point->x > lim.min)
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

void	ft_keyhook_change_col(int key, t_colour *col)
{
	if (key == XK_1)
		*col = ft_get_colour(RED);
	else if (key == XK_2)
		*col = ft_get_colour(GREEN);
	else if (key == XK_3)
		*col = ft_get_colour(BLUE);
	else if (key == XK_4)
		*col = ft_get_colour(YELLOW);
	else if (key == XK_5)
		*col = ft_get_colour(PURPLE);
	else if (key == XK_6)
		*col = ft_get_colour(CYAN);
	else if (key == XK_7)
		*col = ft_get_colour(WHITE);
	else if (key == XK_8)
		*col = ft_get_colour(BLACK);
	else if (key == XK_9)
		*col = ft_get_colour(ORANGE);
	else if (key == XK_0)
		*col = ft_get_colour(PINK);
}
