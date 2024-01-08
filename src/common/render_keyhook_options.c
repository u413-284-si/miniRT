/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:15:52 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 14:41:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_change_mode(uint8_t *options)
{
	if (ft_bit_is_set(*options, O_MODE_SCENE))
	{
		ft_bit_clear(options, O_MODE_SCENE);
		ft_bit_set(options, O_MODE_LIGHT);
	}
	else if (ft_bit_is_set(*options, O_MODE_LIGHT))
	{
		ft_bit_clear(options, O_MODE_LIGHT);
		ft_bit_set(options, O_MODE_CAM);
	}
	else if (ft_bit_is_set(*options, O_MODE_CAM))
	{
		ft_bit_clear(options, O_MODE_CAM);
		ft_bit_set(options, O_MODE_SCENE);
	}
}

static void	ft_toggle_menu_page(uint8_t *options)
{
	ft_bit_toggle(options, O_SHOW_CTRL);
}

static void	ft_toggle_menu(uint8_t *options, const t_mlx_ptrs mlx_ptrs)
{
	ft_bit_toggle(options, O_SHOW_MENU);
	if (!ft_bit_is_set(*options, O_SHOW_MENU))
	{
		mlx_put_image_to_window(mlx_ptrs.mlx_ptr,
			mlx_ptrs.win_ptr, mlx_ptrs.img.ptr, 0, 0);
	}
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
		ft_toggle_menu_page(&render->options);
}
