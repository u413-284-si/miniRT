/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/22 16:53:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	static t_render	render;

	if (argc != 2)
	{
		ft_perror("Usage: ./miniRT file.rt", 0);
		exit(1);
	}
	if (ft_parse_file(argv[1], &render.scene, &render.cam))
		return (1);
	if (ft_render_init(&render))
	{
		ft_render_cleanup(&render);
		return (1);
	}
	ft_render_start_loop(&render);
	ft_render_cleanup(&render);
	return (0);
}
