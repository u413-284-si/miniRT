/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/20 09:55:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include "camera.h"

int	main(int argc, char **argv)
{
	t_image		image;
	t_cam		cam;
	t_viewport	viewport;
	t_entities	scene;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nUsage: ./miniRT file.rt", 2);
		exit(1);
	}
	ft_parse_file(argv[1], &scene, &cam);
	ft_initiate_image(&image);
	ft_initiate_camera(&cam);
	ft_initiate_viewport(&viewport, cam, image);
	ft_create_image(image, cam, viewport, scene);

	return (0);
}
