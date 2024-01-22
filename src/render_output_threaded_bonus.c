/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output_threaded.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:50:09 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/20 13:53:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	*ft_output_threaded(void *arg)
{
	t_render		*render;

	render = ((t_thread_data *)arg)->arg;
	ft_output_as_ppm(render->mlx_ptrs.img);
	ft_toggle_is_printing(render);
	return (NULL);
}

bool	ft_is_printing(t_render *render)
{
	bool	ret;

	pthread_mutex_lock(&render->mut_print);
	ret = render->is_printing;
	pthread_mutex_unlock(&render->mut_print);
	return (ret);
}

void	ft_toggle_is_printing(t_render *render)
{
	pthread_mutex_lock(&render->mut_print);
	render->is_printing = !render->is_printing;
	pthread_mutex_unlock(&render->mut_print);
}
