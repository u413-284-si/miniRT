/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/13 15:18:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"
#include "camera.h"

int	main(int argc, char **argv)
{
	static t_cam		cam;
	static t_entities	scene;

	if (argc != 2)
	{
		ft_putendl_fd("Need a file", 2);
		exit(1);
	}
	ft_parse_file(argv[1], &scene);
	(void)cam;
	/*


	ft_create_scene(&scene);
	ft_initiate_camera(&cam);
	ft_initiate_viewport(&cam);
	ft_create_image(cam, scene);
	*/
	return (0);
}
