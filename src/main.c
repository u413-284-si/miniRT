/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/16 12:02:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


int	main(int argc, char **argv)
{
	static t_engine	engine;

	if (argc != 2)
	{
		ft_perror("Usage: ./miniRT file.rt", 0);
		exit(1);
	}
	if (ft_parse_file(argv[1], &engine.scene, &engine.cam))
		exit(1);
	ft_initiate_image(&engine.image);
	ft_initiate_camera(&engine.cam);
	//ft_initiate_viewport(&engine.vp, engine.cam, engine.image);
	ft_init_renderer(&engine.render, &engine.image, false);
	ft_start_engine(&engine);
	free(engine.scene.obj);
	free(engine.scene.lsrc);
	return (0);
}
