/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_compose_image_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:22:40 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/07 14:22:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "time_bonus.h"

int	ft_draw_scene(t_render *render)
{
	const uint64_t	starttime = ft_get_timeofday_ms();
	const uint32_t	fps = 1000 / (starttime - render->last_render_time);

	ft_render_image(render);
	printf("MS: %lu\n", starttime - render->last_render_time);
	printf("FPS: %u\n", fps);
	render->last_render_time = starttime;
	return (0);
}
