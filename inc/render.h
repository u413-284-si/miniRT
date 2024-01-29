/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 16:23:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/* ====== LIBRARIES ====== */

# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "libft.h"

# include "render_struct.h"

# if IS_BONUS
#  include "render_struct_bonus.h"
#  include "miniRT_config_bonus.h"
#  include "ray_bonus.h"
#  include "manip_bonus.h"
# else
#  include "miniRT_config.h"
#  include "ray.h"
#  include "manip.h"
# endif

# include "render_bit_field.h"
# include "cleanup.h"
# include "error_mlx.h"
# include "utils.h"

/* ====== FUNCTIONS ====== */

// render_init_base.c

/**
 * @brief Initializes the render struct.
 *
 * Initializes the mlx_ptrs struct, the cam struct and the menu struct.
 * Initializes options.
 * @param render	Pointer to render struct.
 * @return t_err	SUCCESS, ERROR.
 */
t_err		ft_render_init(t_render *render);

/**
 * @brief Initializes the render menu.
 *
 * Sets the background and text colour. Also pre-calculates the RB and G colour
 * mixes.
 * @param menu 		Pointer to menu struct
 * @param alpha 	Transparency for menu
 * @param colour 	Background colour
 * @param font_col 	Text colour
 */
void		ft_menu_init(t_menu *menu, uint8_t alpha, uint32_t colour,
				uint32_t font_col);

// render_init_mlx.c

/**
 * @brief Initializes the mlx_ptrs struct.
 *
 * @param mlx_ptrs		Pointer to mlx_ptrs struct.
 * @param win_size		Parsed size of window.
 * @return t_err		SUCCESS, ERROR.
 */
t_err		ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, t_vec2i *win_size);

/**
 * @brief Initializes the mlx img struct.
 *
 * @param mlx_ptrs		Pointer to mlx_ptrs struct.
 * @param size			Image size as int array.
 * @return t_err		SUCCESS, ERROR.
 */
t_err		ft_init_image(t_mlx_ptrs *mlx_ptrs, t_vec2i size);

/**
 * @brief Checks screen size.
 *
 * Gets the screen size and compares it to the window size.
 * If the window size is larger than the screen size, the window size is
 * set to the screen size.
 * @param mlx_ptr	Mlx pointer.
 * @return t_vec2i	Window size.
 */
t_vec2i		ft_check_screen_size(void *mlx_ptr, t_vec2i win_size);

// render_loop_mlx.c

/**
 * @brief Starts the mlx loop.
 *
 * Registers keypresses.
 * Renders the scene to the mlx img in a loop.
 * @param render	Pointer to render struct.
 */
void		ft_render_start_loop(t_render *render);

/**
 * @brief Main loop of the program.
 *
 * Checks if scene has changed. If so, the scene is re-rendered.
 * The menu text is put on top of the image. It needs to be put every
 * loop iterations, else it disappears.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_programm_loop(t_render *render);

/**
 * @brief Wrapper around mlx_loop_end().
 *
 * Can be used to do additional cleanup.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_end_loop(t_render *render);

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
void		ft_put_pix_to_image(t_img *img, int x, int y, int color);

/**
 * @brief Constructs a ray and shoots it through the pixel.
 *
 * Takes the precalculated pixel centre from the camera pixel grid.
 * Shoots a ray from the camera centre through the pixel centre.
 * @param pos		Position of the pixel in the image.
 * @param ray		Partly build Ray struct.
 * @param scene		Scene struct.
 * @param cam		Camera struct.
 * @return t_colour	Colour of the pixel.
 */
t_colour	ft_shoot_ray(t_vec2i pos, t_ray ray, t_entities scene, t_cam cam);

/**
 * @brief Raytraces the scene to the mlx img.
 *
 * Creates rays for each pixel of the image and "shoots" them
 * through the corresponding pixel in the viewport. The colour of
 * each ray is returned and written to the mlx img.
 * @param render	Pointer to render struct.
 */
void		ft_raytrace_image(t_render *render);

// render_blend_background.c

/**
 * @brief Creates a blended colour from colour and menu colour.
 *
 * Uses formula ColC = alpha{ColA} * ColA + (1 - alpha{ColA} ) * ColB.
 * The color of menu is pre-calculated to speed up the process.
 * Also makes use of two simplifications:
 * 1: less variables
 * 2: less precision for division
 * Ad 1: the channels R and B are stored in the same variable. They are
 * far enough apart in memory.
 * Ad 2: Instead of dividing by 255.99 we bit shift by >>8 == 256.
 * @param bg_color
 * @param menu
 * @return uint32_t
 */
uint32_t	ft_fast_alpha_blend(uint32_t bg_color, t_menu menu);

/**
 * @brief Aplha blends current image with menu color to create overlay.
 *
 * For each pixel of the menu size, the menu colour is blended with the
 * corresponding pixel of the current image.
 * The current image pixel is multiplied with the inverse of the alpha value
 * of the menu colour. Both are added together. To speed up the process,
 * the alpha value is pre-calculated. Furthermore, only two variables (rb and g)
 * are used to calc the blended colour.
 * @param render	Pointer to render struct.
 */
void		ft_blend_background(t_render *render);

// menu_put_text.c

/**
 * @brief Puts the current menu page on the screen.
 *
 * @param render	Pointer to render struct.
 */
void		ft_menu_put_text(t_render *render);

// render_keyhook_press.c

/**
 * @brief Handles keypresses.
 *
 * Checks for keypresses and calls the corresponding function.
 * Differentiates between option, select and manipulation keys.
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_keyhook_press(int key, t_render *render);

// render_cleanup.c

/**
 * @brief Frees ressources allocated for mlx.
 *
 * @param mlx_ptrs	Pointer to mlx_ptrs struct.
 */
void		ft_free_mlx(t_mlx_ptrs *mlx_ptrs);

/**
 * @brief Frees ressources allocated for render.
 *
 * Calls all cleanup functions.
 * @param render	Pointer to render struct.
 */
void		ft_render_cleanup(t_render *render);

#endif
