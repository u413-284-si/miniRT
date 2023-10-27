/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/10/27 11:36:26 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "colour.h"

int	main(int argc, char **argv)
{
	int			image_width;
	int			image_height;
	int			i;
	int			j;
	t_colour	pixel;


	image_width = 256;
	image_height = 256;
	if (argc != 2)
	{
		printf("Error\n");
		exit(123);
	}
	printf("P3\n%d %d\n255\n", image_width, image_height);
	j = -1;
	while (++j < image_height)
	{
		i = -1;
		while (++i < image_width)
		{
			pixel.r = (float)i / (image_width - 1);
			pixel.g = (float)j / (image_height - 1);
			pixel.b = 0;
			ft_write_colour(pixel);
		}
	}
	(void)argv;
	return (0);
}
