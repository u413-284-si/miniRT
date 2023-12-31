/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/31 11:45:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/* ====== LIBRARIES ====== */

# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "error_mlx.h"
# include "camera.h"
# include "ft_print.h"
# include "cleanup.h"
# include "entities.h"
# include "miniRT_config.h"
# include "mat4_vec3.h"
# include "print.h"

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
 *
 */
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bytes;
	int		width;
	int		height;
}	t_img;

/**
 * @brief mlx pointers struct.
 *
 * @param mlx_ptr	Pointer to mlx.
 * @param win_ptr	Pointer to mlx window.
 * @param img		mlx img struct.
 */
typedef struct s_mlx_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx_ptrs;

typedef enum e_pages
{
	PAGE_SCENE,
	PAGE_LIGHT,
	PAGE_CAM,
	PAGE_SCENE_CTRL,
	PAGE_LIGHT_CTRL,
	PAGE_CAM_CTRL,
	PAGE_SCENE_LST,
	PAGE_LIGHT_LST
}	t_pages;

typedef struct s_menu
{
	uint8_t		inv_alpha;
	uint32_t	rb;
	uint32_t	g;
	uint32_t	font_col;
	t_pages		cur_page;
}	t_menu;

typedef enum e_mode
{
	CTRL_SCENE,
	CTRL_CAM,
	CTRL_LIGHT
}	t_mode;

/**
 * @brief Overarching render struct.
 *
 * @param mlx_ptrs		mlx pointers struct.
 * @param cam			Camera struct.
 * @param scene			Scene struct.
 * @param image			Image struct.
 * @param vp			Viewport struct.
 */
typedef struct s_render
{
	t_mlx_ptrs	mlx_ptrs;
	t_cam		cam;
	t_entities	scene;
	t_viewport	vp;
	t_menu		menu;
	bool		show_menu;
	t_mode		mode;
}	t_render;

/* ====== FUNCTIONS ====== */

// render_init.c

/**
 * @brief Initializes the mlx_ptrs struct.
 *
 * @param mlx_ptrs		Pointer to mlx_ptrs struct.
 * @param fullscreen	Fullscreen flag.
 * @return t_err		SUCCESS, ERROR.
 */
t_err	ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, bool fullscreen);

/**
 * @brief Initializes the mlx img struct.
 *
 * @param mlx_ptrs		Pointer to mlx_ptrs struct.
 * @param size			Image size as int array.
 * @return t_err		SUCCESS, ERROR.
 */
t_err	ft_init_image(t_mlx_ptrs *mlx_ptrs, int size[2]);

/**
 * @brief Sets the window to fullscreen.
 *
 * @param mlx_ptr	Mlx pointer.
 * @param win_size	Pointer to int array for window size.
 */
void	ft_set_fullscreen(void *mlx_ptr, int win_size[2]);

// render_draw.c

/**
 * @brief Draws a single pixel to the mlx img.
 *
 * Loops for the number of bytes per pixel and writes the colour to the address.
 * @param img	Pointer to mlx img struct.
 * @param x		X coordinate.
 * @param y		Y coordinate.
 * @param color	Colour to write.
 */
void	ft_put_pix_to_image(t_img *img, int x, int y, int color);

/**
 * @brief Renders the scene to the mlx img.
 *
 * Creates rays for each pixel of the image and "shoots" them
 * through the corresponding pixel in the viewport. The colour of
 * each ray is returned and written to the mlx img.
 * @param render	Pointer to render struct.
 */
void	ft_render_image(t_render *render);

// render_output_ppm.c

/**
 * @brief Outputs the current mlx img as a ppm file.
 *
 * @param img_arr	Pointer to mlx img array, cast into int.
 * @param width		Width of the image.
 * @param height	Height of the image.
 * @return t_err	SUCCESS, ERROR.
 */
t_err	ft_output_as_ppm(int *img_arr, int width, int height);

// render_keyhook.c

/**
 * @brief Handles keypresses.
 *
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int		ft_keyhook_press(int key, t_render *render);

// render_keyhook_hittable.c

/**
 * @brief Changes the active hittable.
 *
 * @param key		Keycode of the pressed key.
 * @param scene		Pointer to scene struct.
 */
void	ft_change_active_hittable(int key, t_entities *scene);

/**
 * @brief Manipulates the active hittable.
 *
 * @param key		Keycode of the pressed key.
 * @param hittable	Pointer to hittable struct.
 */
void	ft_manip_hittable(int key, t_hittable *hittable);

/**
 * @brief Manipulates the active sphere.
 *
 * @param key		Keycode of the pressed key.
 * @param sp		Pointer to sphere struct.
 */
void	ft_manip_sphere(int key, t_sphere *sp);

/**
 * @brief Manipulates the active plane.
 *
 * @param key		Keycode of the pressed key.
 * @param pl		Pointer to plane struct.
 */
void	ft_manip_plane(int key, t_plane *pl);

/**
 * @brief Manipulates the active cylinder.
 *
 * @param key		Keycode of the pressed key.
 * @param cy		Pointer to cylinder struct.
 */
void	ft_manip_cylinder(int key, t_cylinder *cy);

// render_keyhook_utils.c

void	ft_keyhook_mv_point(int key, t_vec3 *point);

void	ft_keyhook_rot_vec(int key, t_vec3 *vector);

void	ft_keyhook_change_col(int key, t_colour *col);

// render_loop_mlx.c

/**
 * @brief Starts the mlx loop.
 *
 * Registers keypresses.
 * Renders the scene to the mlx img in a loop.
 * @param render	Pointer to render struct.
 */
void	ft_render_start_loop(t_render *render);


void	ft_init_menu(t_menu *menu, uint8_t alpha, uint32_t colour, uint32_t font_col);
void	ft_draw_menu(t_render *render);

void	ft_manip_light(int key, t_entities *scene);
void	ft_manip_light_src(int key, t_light *light);

#endif
