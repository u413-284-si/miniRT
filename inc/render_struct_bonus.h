/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 17:48:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_STRUCT_BONUS_H
# define RENDER_STRUCT_BONUS_H

/* ====== LIBRARIES ====== */

# include "render_struct.h"
# include "entities_bonus.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Bit field which keeps track of different options.
 *
 * @param O_MODE_SCENE		Active mode: Scene.
 * @param O_MODE_LIGHT		Active mode: Light.
 * @param O_MODE_CAM		Active mode: Camera.
 * @param O_SCENE_CHANGED	Scene changed flag.
 * @param O_SHOW_MENU		Show menu flag.
 * @param O_SHOW_CTRL		Show controls flag.
 * @param O_MANIP_LOW		Manipulation speed: Low.
 * @param O_MANIP_MID		Manipulation speed: Medium.
 * @param O_MANIP_HIGH		Manipulation speed: High.
 * @param O_SHOW_FPS		Show FPS flag.
 * @param O_IS_THREADED		Is threaded flag.
 * @param O_IS_ANTI_ALIAS	Is anti-aliasing flag.
 * @param O_SHOW_OPTIONS	Show options flag.
 * @param O_IS_PRINTING		Is printing flag.
 */
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
 * @param mlx_ptrs			mlx pointers struct.
 * @param cam				Camera struct.
 * @param scene				Scene struct.
 * @param win_size			Window size.
 * @param mouse				Mouse struct.
 * @param menu				Menu struct.
 * @param options			Bit field of options.
 * @param active_hittable	Selected hittable entity.
 * @param active_light		Selected light entity.
 * @param last_render_time	Time delta for the last rendered frame.
 * @param is_printing		Is printing flag.
 * @param mut_print			Mutex for is_printing flag.
 * @param sample_buffer		Sample buffer to store generated image samples.
 * @param sample_goal		Amount of samples to generate.
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
