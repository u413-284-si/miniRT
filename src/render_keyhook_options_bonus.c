/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_options_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:15:52 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 10:34:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

static void	ft_start_printing(t_render *render)
{
	ft_option_set(&render->options, O_IS_PRINTING);
	ft_toggle_is_printing(render);
	ft_spin_detached_thread(render, ft_output_threaded);
}

static void	ft_toggle_anti_alias(t_render *render)
{
	ft_option_toggle(&render->options, O_IS_ANTI_ALIAS);
	if (ft_option_isset(render->options, O_IS_ANTI_ALIAS))
		render->sample_goal = SAMPLE_SIZE;
	else
		render->sample_goal = 1;
}

void	ft_change_options_bonus(int key, t_render *render)
{
	if (key == XK_o)
		ft_option_toggle(&render->options, O_SHOW_OPTIONS);
	else if (key == XK_p)
		ft_start_printing(render);
	else if (key == XK_j)
		ft_option_toggle(&render->options, O_IS_THREADED);
	else if (key == XK_k)
		ft_toggle_anti_alias(render);
	else if (key == XK_l)
		ft_option_toggle(&render->options, O_SHOW_FPS);
}
