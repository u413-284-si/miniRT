/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_options_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:15:52 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/20 14:05:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

static void	ft_change_inc(uint32_t *options)
{
	if (ft_option_isset(*options, O_MANIP_LOW))
	{
		ft_option_clear(options, O_MANIP_LOW);
		ft_option_set(options, O_MANIP_MID);
	}
	else if (ft_option_isset(*options, O_MANIP_MID))
	{
		ft_option_clear(options, O_MANIP_MID);
		ft_option_set(options, O_MANIP_HIGH);
	}
	else if (ft_option_isset(*options, O_MANIP_HIGH))
	{
		ft_option_clear(options, O_MANIP_HIGH);
		ft_option_set(options, O_MANIP_LOW);
	}
}

static void	ft_change_mode(uint32_t *options)
{
	if (ft_option_isset(*options, O_MODE_SCENE))
	{
		ft_option_clear(options, O_MODE_SCENE);
		ft_option_set(options, O_MODE_LIGHT);
	}
	else if (ft_option_isset(*options, O_MODE_LIGHT))
	{
		ft_option_clear(options, O_MODE_LIGHT);
		ft_option_set(options, O_MODE_CAM);
	}
	else if (ft_option_isset(*options, O_MODE_CAM))
	{
		ft_option_clear(options, O_MODE_CAM);
		ft_option_set(options, O_MODE_SCENE);
	}
}

static void	ft_toggle_menu(uint32_t *options, const t_mlx_ptrs mlx_ptrs)
{
	ft_option_toggle(options, O_SHOW_MENU);
	if (!ft_option_isset(*options, O_SHOW_MENU))
	{
		mlx_put_image_to_window(mlx_ptrs.mlx_ptr,
			mlx_ptrs.win_ptr, mlx_ptrs.img.ptr, 0, 0);
	}
}

static void	ft_start_printing(t_render *render)
{
	ft_toggle_is_printing(render);
	ft_spin_detached_thread(render, ft_output_threaded);
}

void	ft_change_options(int key, t_render *render)
{
	if (key == XK_Escape)
		mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	else if (key == XK_i)
		ft_toggle_menu(&render->options, render->mlx_ptrs);
	else if (key == XK_Control_L)
		ft_change_mode(&render->options);
	else if (key == XK_Shift_L)
		ft_option_toggle(&render->options, O_SHOW_CTRL);
	else if (key == XK_u)
		ft_change_inc(&render->options);
	else if (key == XK_o)
		ft_option_toggle(&render->options, O_SHOW_FPS);
	else if (key == XK_p)
		ft_start_printing(render);
	else if (key == XK_j)
		ft_option_toggle(&render->options, O_IS_THREADED);
}
