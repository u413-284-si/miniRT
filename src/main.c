/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/17 14:28:38 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_image		image;
	t_cam		cam;
	t_viewport	viewport;
	t_entities	scene;

	if (argc != 2)
	{
		printf("Error\n");
		exit(123);
	}
	ft_create_scene(&scene);
	ft_initiate_image(&image);
	ft_initiate_camera(&cam);
	ft_initiate_viewport(&viewport, cam, image);
	ft_create_image(image, cam, viewport, scene);
	(void)argv;
	return (0);
}
