/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cleanup_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:43:24 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 16:54:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ft_render_cleanup(t_render *render)
{
	free(render->scene.obj);
	free(render->scene.lsrc);
	ft_free_mlx(&render->mlx_ptrs);
	free(render->cam.pix_cache);
	free(render->sample_buffer);
	pthread_mutex_destroy(&render->mut_print);
}
