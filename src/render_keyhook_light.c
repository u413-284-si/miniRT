/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:40:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/31 11:44:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_manip_light_src(int key, t_light *light)
{
	if (key >= XK_0 && key <= XK_9)
		ft_keyhook_change_col(key, &light->colour);
	else if (key == XK_r)
		light->ratio -= MV_UNIT;
	else if (key == XK_f)
		light->ratio += MV_UNIT;
	else
		ft_keyhook_mv_point(key, &light->pos);
}

void	ft_manip_light(int key, t_entities *scene)
{
	if (key == XK_n || key == XK_m)
		;//ft_change_active_light(key, scene);
	else
		ft_manip_light_src(key, &scene->lsrc[0]);
}
