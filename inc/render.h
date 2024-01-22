/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 10:20:33 by gwolf            ###   ########.fr       */
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

# include "error_mlx.h"
# include "camera.h"
# include "cleanup.h"
# include "mat4_vec3.h"
# include "vec2.h"
# include "render_menu.h"

# if IS_BONUS
#  include "miniRT_config_bonus.h"
#  include "ray_bonus.h"
#  include "entities_bonus.h"
#  include "render_bit_field_bonus.h"
#  include "threads_bonus.h"
# else
#  include "miniRT_config.h"
#  include "ray.h"
#  include "entities.h"
#  include "render_bit_field.h"
# endif

/* ====== MACROS ========*/

# define NUM_COLOURS 9
# define NUM_RAINBOW_COLOURS 7

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
	t_mouse			mouse;
	t_menu			menu;
	uint32_t		options;
	int				active_hittable;
	int				active_light;
}	t_render;

/**
 * @brief Enumeration of colour names.
 *
 * Used to get predefined colours.
 */
typedef enum e_col_name
{
	RED = 0,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	INDIGO,
	PURPLE,
	WHITE,
	BLACK
}	t_col_name;

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

// render_init_mlx.c

/**
 * @brief Initializes the mlx_ptrs struct.
 *
 * @param mlx_ptrs		Pointer to mlx_ptrs struct.
 * @param fullscreen	Fullscreen flag.
 * @return t_err		SUCCESS, ERROR.
 */
t_err		ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, bool fullscreen);

/**
 * @brief Initializes the mlx img struct.
 *
 * @param mlx_ptrs		Pointer to mlx_ptrs struct.
 * @param size			Image size as int array.
 * @return t_err		SUCCESS, ERROR.
 */
t_err		ft_init_image(t_mlx_ptrs *mlx_ptrs, t_vec2i size);

/**
 * @brief Sets the window to fullscreen.
 *
 * @param mlx_ptr	Mlx pointer.
 * @return t_vec2i	Window size.
 */
t_vec2i		ft_set_fullscreen(void *mlx_ptr);

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
 * @return uint32_t	Colour of the pixel.
 */
uint32_t	ft_shoot_ray(t_vec2i pos, t_ray ray, t_entities scene, t_cam cam);

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

// render_keyhook_options.c

/**
 * @brief Handles option keys.
 *
 * Escape: Exit program.
 * Shift: Show controls.
 * Control: Change mode.
 * 'I': Toggle menu.
 * 'U': Change increment value.
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 */
void		ft_change_options(int key, t_render *render);

// render_keyhook_select.c

/**
 * @brief Changes the active hittable or light source.
 *
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 */
void		ft_change_select(int key, t_render *render);

// render_keyhook_hittable.c

/**
 * @brief Manipulates the active hittable.
 *
 * @param key		Keycode of the pressed key.
 * @param hittable	Pointer to hittable struct.
 * @param inc		Increment value.
 */
void		ft_manip_hittable(int key, t_hittable *hittable, float inc);

/**
 * @brief Manipulates the active sphere.
 *
 * @param key		Keycode of the pressed key.
 * @param sp		Pointer to sphere struct.
 * @param inc		Increment value.
 */
void		ft_manip_sphere(int key, t_sphere *sp, float inc);

/**
 * @brief Manipulates the active plane.
 *
 * @param key		Keycode of the pressed key.
 * @param pl		Pointer to plane struct.
 * @param inc		Increment value.
 */
void		ft_manip_plane(int key, t_plane *pl, float inc);

/**
 * @brief Manipulates the active cylinder.
 *
 * @param key		Keycode of the pressed key.
 * @param cy		Pointer to cylinder struct.
 * @param inc		Increment value.
 */
void		ft_manip_cylinder(int key, t_cylinder *cy, float inc);

// render_keyhook_camera.c

/**
 * @brief Rotates the camera with a keypress.
 *
 * Arrow Left, Right (Rotate X)
 * Arrow Up, Down (Rotate Y)
 * @param key		Keycode of the pressed key.
 * @param direction	Camera direction vector.
 * @param inc		Increment value.
 */
void		ft_keyhook_rot_cam(int key, t_vec3 *direction, float inc);

/**
 * @brief Moves the camera with a keypress.
 *
 * The camera moves along its orthonormal basis.
 * WS (Forward, Backward)
 * AD (Left, Right)
 * QE (Up, Down)
 * @param key	Keycode of the pressed key.
 * @param cam	Pointer to camera struct.
 * @param inc	Increment value.
 */
void		ft_keyhook_move_cam(int key, t_cam *cam, float inc);

/**
 * @brief Changes the camera FOV with a keypress.
 *
 * R (Decrease FOV)
 * F (Increase FOV)
 * @param key	Keycode of the pressed key.
 * @param cam	Pointer to camera struct.
 * @param inc	Increment value.
 */
void		ft_keyhook_fov_cam(int key, t_cam *cam, float inc);

/**
 * @brief Manipulates the camera with a keypress.
 *
 * Checks for keypresses and calls the corresponding function.
 * Re-calculates different aspects of camera (viewport dimensions,
 * base vectors, pixel grid) if necessary.
 * @param key		Keycode of the pressed key.
 * @param cam		Pointer to camera struct.
 * @param inc		Increment value.
 * @param options	Options bit field.
 */
void		ft_manip_cam(int key, t_cam *cam, float inc, uint32_t *options);

// render_keyhook_light.c

/**
 * @brief Manipulates the active light.
 *
 * Checks for keypresses and calls the corresponding function.
 * @param key		Keycode of the pressed key.
 * @param scene		Pointer to scene struct.
 * @param active	Pointer to index of active light.
 * @param inc		Increment value.
 */
void		ft_manip_light(int key, t_entities *scene, int *active, float inc);

/**
 * @brief Manipulates the ambient light.
 *
 * Changes colour and ratio of ambient light.
 * @param key		Keycode of the pressed key.
 * @param ambient	Pointer to ambient light struct.
 * @param inc		Increment value.
 */
void		ft_manip_ambient(int key, t_light *ambient, float inc);

/**
 * @brief Manipulates a light source.
 *
 * Changes colour, ratio and position of a light source.
 * @param key	Keycode of the pressed key.
 * @param light	Pointer to light source struct.
 * @param inc	Increment value.
 */
void		ft_manip_light_src(int key, t_light *light, float inc);

// render_keyhook_utils.c

/**
 * @brief Increases or decreases a value with a keypress.
 *
 * If value is negative, it is set to 0.
 * If value is more than max, it is set to max.
 * R or T (Decrease value)
 * F or G (Increase value)
 * @param key	Keycode of the pressed key.
 * @param value	Pointer to value to change.
 * @param max	Maximum value.
 * @param inc	Increment value.
 */
void		ft_keyhook_inc_dec(int key, float *value, float max, float inc);

/**
 * @brief Moves a 3D point with a keypress.
 *
 * Movement is only applied if it is within the limits of the scene.
 * WS (Forward, Backward)
 * AD (Left, Right)
 * QE (Up, Down)
 * @param key	Keycode of the pressed key.
 * @param point	3D point to move.
 * @param inc	Increment value.
 */
void		ft_keyhook_mv_point(int key, t_vec3 *point, float inc);

/**
 * @brief Rotates a 3D vector with a keypress.
 *
 * Arrow Left, Right (Rotate X)
 * Arrow Up, Down (Rotate Y)
 * @param key		Keycode of the pressed key.
 * @param vector	3D vector to rotate.
 * @param inc		Increment value.
 */
void		ft_keyhook_rot_vec(int key, t_vec3 *vector, float inc);

/**
 * @brief Get the current increment value
 *
 * @param options	Options bit field.
 * @return float	Increment value.
 */
float		ft_get_increment(uint32_t options);

//render_keyhook_colour.c

/**
 * @brief Changes the colour with a keypress.
 *
 * Number keys have predefined colors associated.
 * @param key	Keycode of the pressed key.
 * @param col	Pointer to colour struct.
 * @param inc	Increment value.
 */
void		ft_keyhook_change_col(int key, t_colour *col, float inc);

/**
 * @brief Returns a colour based on the given colour name.
 *
 * @param col_name	Colour name.
 * @return t_colour	Colour.
 */
t_colour	ft_get_colour(t_col_name col_name);

/**
 * @brief Interpolates between two colours.
 *
 * Uses ft_get_colour() to get seven colours of rainbow.
 * @param result	Pointer to the resulting colour.
 * @param progress	A float between 0 and 1, indicating the position
 * 					in the color transition.
 */
void		ft_interpolate_colour(t_colour *result, float progress);

/**
 * @brief Interpolates between two colours while keeping track of progress.
 *
 * The progress of interpolation is stored in a static variable.
 * If it reaches 1.0, it is reset to 0.0, and vice versa.
 * Calls ft_interpolate_colour() to do the actual interpolation.
 * @param result	Pointer to the resulting colour.
 * @param inc		Interpolation increment.
 */
void		ft_static_interpolate(t_colour *result, float inc);

// render_mouse.c

/**
 * @brief Handles mouse button presses.
 *
 * If right mouse button is pressed, the last mouse position is saved
 * and the right mouse button flag is set.
 * @param button	Button code.
 * @param x			X coordinate.
 * @param y			Y coordinate.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_mouse_hook_press(int button, int x, int y, t_render *render);

/**
 * @brief Handles mouse button releases.
 *
 * If left mouse button is released, the left mouse button flag is toggled.
 * If right mouse button is released, the right mouse button flag is cleared.
 * @param button	Button code.
 * @param x			X coordinate.
 * @param y			Y coordinate.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_mouse_hook_release(int button, int x, int y, t_render *render);

/**
 * @brief Handles mouse movement.
 *
 * If right mouse button is pressed, the camera is rotated with
 * ft_mouse_hook_rot_cam().
 * @param x			X coordinate.
 * @param y			Y coordinate.
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_mouse_hook_move(int x, int y, t_render *render);

/**
 * @brief Rotates the camera with the mouse.
 *
 * Calc the delta between the last mouse position and the current mouse position.
 * The delta is multiplied by 0.1 to slow down the rotation.
 * Rotate the camera direction vector with the delta.
 * Re-calculate the camera base vectors and pixel grid.
 * @param x			X coordinate.
 * @param y			Y coordinate.
 * @param render	Pointer to render struct.
 */
void		ft_mouse_hook_rot_cam(int x, int y, t_render *render);

// render_cleanup.c

/**
 * @brief Frees ressources allocated for mlx.
 *
 * @param mlx_ptrs	Pointer to mlx_ptrs struct.
 */
void		ft_free_mlx(t_mlx_ptrs *mlx_ptrs);

/**
 * @brief Frees ressources allocated for scene.
 *
 * Just a wrapper around two free calls.
 * @param scene	Pointer to scene struct.
 */
void		ft_free_scene(t_entities *scene);

/**
 * @brief Frees ressources allocated for render.
 *
 * Calls all cleanup functions.
 * @param render	Pointer to render struct.
 */
void		ft_render_cleanup(t_render *render);

#endif
