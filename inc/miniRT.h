/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:45 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/07 10:11:13 by gwolf            ###   ########.fr       */
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

/* ====== MACROS ====== */

# define MV_UNIT 1.0
# define X 0
# define Y 1

/* ====== TYPEDEFS ====== */

typedef struct s_mouse {
	bool	left;
	bool	right;
	int		last_left[2];
	int		last_right[2];
}	t_mouse;

typedef struct s_engine {
	t_render	render;
	t_entities	scene;
	t_cam		cam;
	t_viewport	vp;
	t_image		image;
	t_mouse		mouse;
}	t_engine;



/* ====== FUNCTIONS ====== */

// engine_loop.c
void	ft_start_engine(t_engine *engine);

// engine_draw.c
int		ft_draw_scene(t_engine *engine);

// engine_keyhook.c
int		ft_keyhook_press(int key, t_engine *engine);

int	ft_mouse_hook_press(int button, int x, int y, t_engine *engine);
int	ft_mouse_hook_release(int button, int x, int y, t_engine *engine);
int	ft_mouse_hook_move(int x, int y, t_engine *engine);
void	ft_mouse_move_center(t_engine *engine);
void	ft_mouse_calc_delta(int x, int y, t_engine *engine, int delta[2]);

#endif
