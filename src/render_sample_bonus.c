/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sample_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:44:09 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 09:15:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ft_clear_buffer(t_render *render)
{
	int	i;

	i = -1;
	while (i++ < render->cam.image.x * render->cam.image.y - 1)
		render->sample_buffer[i] = (t_colour){0, 0, 0};
}

void	ft_copy_buffer_to_image(t_render *render, uint8_t cur_sample)
{
	int			i;
	uint32_t	*image;
	t_colour	colour;

	i = -1;
	image = (uint32_t *)render->mlx_ptrs.img.addr;
	while (i++ < render->cam.image.x * render->cam.image.y - 1)
	{
		colour = render->sample_buffer[i];
		if (cur_sample != 1)
			colour = ft_scale_colour(colour, 1 / (float)cur_sample);
		image[i] = ft_convert_colour2int(colour);
	}
}

int	ft_single_sample(t_render *render)
{
	if (ft_option_isset(render->options, O_IS_THREADED))
	{
		if (ft_spin_threads(render, ft_raytrace_sample_threaded))
		{
			ft_option_clear(&render->options, O_IS_THREADED);
			ft_option_set(&render->options, O_SCENE_CHANGED);
			return (1);
		}
	}
	else
		ft_raytrace_sample(render);
	ft_copy_buffer_to_image(render, 1);
	if (ft_option_isset(render->options, O_IS_THREADED))
	{
		if (ft_spin_threads(render, ft_blend_background_threaded))
		{
			ft_option_clear(&render->options, O_IS_THREADED);
			ft_option_set(&render->options, O_SCENE_CHANGED);
			return (1);
		}
	}
	else
		ft_blend_background(render);
	return (0);
}

int	ft_anti_alias_sample(t_render *render, uint8_t cur_sample)
{
	if (ft_option_isset(render->options, O_IS_THREADED))
	{
		if (ft_spin_threads(render, ft_add_raytrace_sample_threaded))
		{
			ft_option_clear(&render->options, O_IS_THREADED);
			ft_option_set(&render->options, O_SCENE_CHANGED);
			return (1);
		}
	}
	else
		ft_add_raytrace_sample(render);
	ft_copy_buffer_to_image(render, cur_sample);
	if (cur_sample == 1 && ft_option_isset(render->options, O_IS_THREADED))
	{
		if (ft_spin_threads(render, ft_blend_background_threaded))
		{
			ft_option_clear(&render->options, O_IS_THREADED);
			ft_option_set(&render->options, O_SCENE_CHANGED);
			return (1);
		}
	}
	else if (cur_sample == 1)
		ft_blend_background(render);
	return (0);
}

int	ft_render_sample(t_render *render, uint8_t *cur_sample)
{
	const uint64_t	starttime = ft_get_time_ms();

	if (render->sample_goal == 1)
	{
		if (ft_single_sample(render))
			return (1);
	}
	else
	{
		if (*cur_sample == 0)
			ft_clear_buffer(render);
		if (ft_anti_alias_sample(render, *cur_sample + 1))
			return (1);
	}
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
		render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
	render->last_render_time = ft_get_time_ms() - starttime;
	(*cur_sample)++;
	return (0);
}
