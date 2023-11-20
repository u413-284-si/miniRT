/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/20 12:33:16 by gwolf            ###   ########.fr       */
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
		ft_perror("Usage: ./miniRT file.rt", 0);
		exit(1);
	}
	if (ft_parse_file(argv[1], &scene, &cam))
		exit(1);
	ft_initiate_image(&image);
	ft_initiate_camera(&cam);
	ft_initiate_viewport(&viewport, cam, image);
	ft_create_image(image, cam, viewport, scene);
	free(scene.obj);
	free(scene.lsrc);
	return (0);
}
