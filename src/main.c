/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/12 17:51:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	static t_entities entities;

	if (argc != 2)
	{
		ft_terminate("Need a file", 0);
	}
	ft_parse_file(argv[1], &entities);
	/*
	t_cam		cam;
	t_entities	scene;

	ft_create_scene(&scene);
	ft_initiate_camera(&cam);
	ft_initiate_viewport(&cam);
	ft_create_image(cam, scene);
	*/
	return (0);
}
