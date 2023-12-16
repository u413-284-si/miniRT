/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/16 12:18:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	static t_engine	engine;

	if (argc != 2)
	{
		ft_perror("Usage: ./miniRT file.rt", 0);
		return (1);
	}
	if (ft_parse_file(argv[1], &engine.scene, &engine.cam))
		return (1);
	if (ft_initiate_camera(&engine.cam))
	{
		ft_free_stuff(engine.scene.obj, engine.scene.lsrc, NULL);
		return (1);
	}
	if (ft_init_renderer(&engine.render, &engine.cam.screen, false))
	{
		ft_free_stuff(engine.scene.obj, engine.scene.lsrc,
			engine.cam.cached_rays);
		return (1);
	}
	ft_start_engine(&engine);
	ft_free_stuff(engine.scene.obj, engine.scene.lsrc,
		engine.cam.cached_rays);
	return (0);
}
