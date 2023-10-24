/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/10/23 14:56:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	int		image_width;
	int		image_height;
	int		i;
	int		j;
	float	r;
	float	g;
	float	b;
	int		ir;
	int		ig;
	int		ib;

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
			r = (float)i / (image_width - 1);
			g = (float)j / (image_height - 1);
			b = 0;
			ir = (int)(255.99 * r);
			ig = (int)(255.99 * g);
			ib = (int)(255.99 * b);
			printf("%d %d %d\n", ir, ig, ib);
		}
	}
	(void)argv;
	return (0);
}
