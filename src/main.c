/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/26 12:29:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	static t_render	render;

	if (argc != 2)
	{
		ft_perror("Usage: ./miniRT file.rt", 0);
		return (1);
	}
	if (ft_parse_file(argv[1], &render.scene, &render.cam, &render.win_size))
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
