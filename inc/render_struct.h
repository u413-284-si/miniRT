/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 15:18:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_STRUCT_H
# define RENDER_STRUCT_H

/* ====== LIBRARIES ====== */

# include <stdbool.h>
# include <stdint.h>

# include "vec2.h"
# include "camera.h"
# if IS_BONUS
#  include "entities_bonus.h"
# else
#  include "entities.h"
# endif

/* ====== TYPEDEFS ====== */

/**
 * @brief mlx img struct.
 *
 * @param ptr		Pointer to mlx img.
 * @param addr		Pointer to the char *buffer of the mlx img.
 * @param bpp		Bytes per pixel.
 * @param line_len	Line length.
 * @param endian	Endian.
 * @param bytes		Number of bytes per pixel.
 * @param size		Size of the img as int vector.
 */
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bytes;
	t_vec2i	size;
}	t_img;

/**
 * @brief mlx pointers struct.
 *
 * @param mlx_ptr	Pointer to mlx.
 * @param win_ptr	Pointer to mlx window.
 * @param img		mlx img struct for rendered image.
 * @param veil		mlx img struct for menu overlay.
 */
typedef struct s_mlx_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	veil;
}	t_mlx_ptrs;

/**
 * @brief Mouse struct.
 *
 * @param left		Left mouse button pressed flag.
 * @param right		Right mouse button pressed flag.
 * @param last_pos	Last mouse position.
 */
typedef struct s_mouse
{
	bool	left;
	bool	right;
	t_vec2i	last_pos;
}	t_mouse;

/**
 * @brief Menu struct.
 *
 * @param inv_alpha		Inverse of the transparency value.
 * @param rb			Background colour channel R and B.
 * @param g				Background colour channel G.
 * @param font_col		Text colour.
 */
typedef struct s_menu
{
	uint8_t		inv_alpha;
	uint32_t	rb;
	uint32_t	g;
	uint32_t	font_col;
}	t_menu;

# ifndef IS_BONUS

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
	O_MANIP_HIGH = 9
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
	t_mlx_ptrs	mlx_ptrs;
	t_cam		cam;
	t_entities	scene;
	t_vec2i		win_size;
	t_mouse		mouse;
	t_menu		menu;
	uint32_t	options;
	int			active_hittable;
	int			active_light;
}	t_render;
# endif

#endif
