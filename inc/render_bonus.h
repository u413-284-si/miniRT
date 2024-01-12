/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/09 17:42:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

/* ====== LIBRARIES ====== */

# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "error_mlx.h"
# include "camera_bonus.h"
# include "ft_print.h"
# include "cleanup.h"
# include "entities_bonus.h"
# include "miniRT_config_bonus.h"

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

// render_loop_mlx.c

/**
 * @brief Starts the mlx loop.
 *
 * Registers keypresses.
 * Renders the scene to the mlx img in a loop.
 * @param render	Pointer to render struct.
 */
void	ft_render_start_loop(t_render *render);

#endif
