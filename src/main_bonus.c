/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/21 11:06:46 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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
