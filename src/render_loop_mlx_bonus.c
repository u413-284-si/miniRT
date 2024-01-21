/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_mlx_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:37:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/21 12:34:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

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

int	ft_first_sample(t_render *render)
{
	if (ft_option_isset(render->options, O_IS_THREADED))
	{
		if (ft_spin_threads(render, ft_render_image_threaded)
			|| ft_spin_threads(render, ft_blend_background_threaded))
		{
			ft_option_clear(&render->options, O_IS_THREADED);
			ft_option_set(&render->options, O_SCENE_CHANGED);
			return (1);
		}
	}
	else
	{
		ft_render_image(render);
		ft_blend_background(render);
	}
	ft_copy_buffer_to_image(render, 1);
	return (0);
}

int	ft_next_sample(t_render *render, uint8_t cur_sample)
{
	if (ft_option_isset(render->options, O_IS_THREADED))
	{
		if (ft_spin_threads(render, ft_add_sample_threaded))
		{
			ft_option_clear(&render->options, O_IS_THREADED);
			ft_option_set(&render->options, O_SCENE_CHANGED);
			return (1);
		}
	}
	else
		ft_add_sample(render);
	ft_copy_buffer_to_image(render, cur_sample);
	return (0);
}

int	ft_programm_loop(t_render *render)
{
	const uint64_t	starttime = ft_get_time_ms();
	static uint8_t	cur_sample;

	if (ft_option_isset(render->options, O_SCENE_CHANGED))
	{
		cur_sample = 0;
		ft_option_clear(&render->options, O_SCENE_CHANGED);
	}
	if (cur_sample < render->sample_goal)
	{
		if (cur_sample == 0)
			ft_first_sample(render);
		else
			ft_next_sample(render, cur_sample + 1);
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		render->last_render_time = ft_get_time_ms() - starttime;
		cur_sample++;
	}
	ft_menu_put_text(render);
	return (0);
}

int	ft_end_loop(t_render *render)
{
	if (ft_is_printing(render))
		return (0);
	mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	return (0);
}

void	ft_render_start_loop(t_render *render)
{
	mlx_hook(render->mlx_ptrs.win_ptr, KeyPress, KeyPressMask,
		ft_keyhook_press, render);
	mlx_hook(render->mlx_ptrs.win_ptr, ButtonPress, ButtonPressMask,
		ft_mouse_hook_press, render);
	mlx_hook(render->mlx_ptrs.win_ptr, ButtonRelease, ButtonReleaseMask,
		ft_mouse_hook_release, render);
	mlx_hook(render->mlx_ptrs.win_ptr, MotionNotify, ButtonMotionMask,
		ft_mouse_hook_move, render);
	mlx_hook(render->mlx_ptrs.win_ptr, DestroyNotify, StructureNotifyMask,
		ft_end_loop, render);
	mlx_loop_hook(render->mlx_ptrs.mlx_ptr, ft_programm_loop, render);
	mlx_loop(render->mlx_ptrs.mlx_ptr);
}
