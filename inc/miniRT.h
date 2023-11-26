/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:45 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/26 10:39:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdio.h>
# include <fcntl.h>				// req for open()
# include <unistd.h>			// req for read(), write(), close()

// Home-grown libs
# include "ft_print.h"
# include "init.h"
# include "parse.h"
# include "camera.h"
# include "render.h"

/* ====== TYPEDEFS ====== */

typedef struct s_engine {
	t_render	render;
	t_entities	scene;
	t_cam		cam;
	t_viewport	vp;
	t_image		image;
}	t_engine;

/* ====== FUNCTIONS ====== */

// engine_loop.c
void	ft_start_engine(t_engine *engine);

// engine_draw.c
int		ft_draw_scene(t_engine *engine);

// engine_keyhook.c
int		ft_keyhook_press(int key, t_engine *engine);

#endif
