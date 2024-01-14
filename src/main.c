/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/14 07:41:05 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	static t_render	render;

	if (argc != 2)
	{
		ft_perror("Usage: ./miniRT file.rt", 0);
		exit(1);
	}
	if (ft_parse_file(argv[1], &render.scene, &render.cam))
		return (1);
	if (ft_init_mlx_ptrs(&render.mlx_ptrs, false))
	{
		ft_free_scene(&render.scene);
		return (1);
	}
	if (ft_cam_init(&render.cam, render.mlx_ptrs.img.size))
	{
		ft_free_mlx(render.mlx_ptrs.mlx_ptr, render.mlx_ptrs.win_ptr,
			render.mlx_ptrs.img.ptr, render.mlx_ptrs.veil.ptr);
		ft_free_scene(&render.scene);
		return (1);
	}
	ft_menu_init(&render.menu, MENU_OPACITY, MENU_BACK, MENU_FONT);
	ft_render_start_loop(&render);
	ft_free_scene(&render.scene);
	free(render.cam.ray_cache);
	return (0);
}
