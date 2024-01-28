/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 16:22:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_STRUCT_BONUS_H
# define RENDER_STRUCT_BONUS_H

/* ====== LIBRARIES ====== */

# include "render_struct.h"
# include "entities_bonus.h"

/* ====== TYPEDEFS ====== */

typedef enum e_options
{
	O_MODE_SCENE = 1,
	O_MODE_LIGHT = 2,
	O_MODE_CAM = 3,
	O_SCENE_CHANGED = 4,
	O_SHOW_MENU = 5,
	O_SHOW_CTRL = 6,
	O_MANIP_LOW = 7,
	O_MANIP_MID = 8,
	O_MANIP_HIGH = 9,
	O_SHOW_FPS = 10,
	O_IS_THREADED = 11,
	O_IS_ANTI_ALIAS = 12,
	O_SHOW_OPTIONS = 13,
	O_IS_PRINTING = 14
}	t_options;

/**
 * @brief Overarching render struct.
 *
 * @param mlx_ptrs		mlx pointers struct.
 * @param cam			Camera struct.
 * @param scene			Scene struct.
 */
typedef struct s_render
{
	t_mlx_ptrs		mlx_ptrs;
	t_cam			cam;
	t_entities		scene;
	t_vec2i			win_size;
	t_mouse			mouse;
	t_menu			menu;
	uint32_t		options;
	int				active_hittable;
	int				active_light;
	uint64_t		last_render_time;
	bool			is_printing;
	pthread_mutex_t	mut_print;
	t_colour		*sample_buffer;
	uint8_t			sample_goal;
}	t_render;

#endif
