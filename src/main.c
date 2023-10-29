/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/10/29 12:41:37 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_cam		cam;
	t_entities	scene;

	if (argc != 2)
	{
		printf("Error\n");
		exit(123);
	}
	ft_create_scene(&scene);
	ft_initiate_camera(&cam);
	ft_initiate_viewport(&cam);
	ft_create_image(cam, scene);
	(void)argv;
	return (0);
}
