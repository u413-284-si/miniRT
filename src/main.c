/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/02 23:36:23 by gwolf            ###   ########.fr       */
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
	ft_cam_init(&render.cam, render.mlx_ptrs.img.size);
	ft_init_menu(&render.menu, MENU_OPACITY, MENU_BACK, MENU_FONT);
	ft_render_start_loop(&render);
	ft_free_scene(&render.scene);
	return (0);
}
