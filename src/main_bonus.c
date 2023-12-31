/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/25 14:06:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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
	ft_initiate_camera(&render.cam);
	ft_initiate_viewport(&render.vp, render.cam, render.mlx_ptrs.img.width, \
		render.mlx_ptrs.img.height);
	ft_render_start_loop(&render);
	ft_free_scene(&render.scene);
	return (0);
}