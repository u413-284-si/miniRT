/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 10:16:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

/* ====== LIBRARIES ====== */

# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "libft.h"

# include "error_mlx.h"
# include "camera.h"
# include "cleanup.h"
# include "vec2.h"
# include "render_menu.h"

# include "miniRT_config_bonus.h"
# include "ray_bonus.h"
# include "entities_bonus.h"
# include "render_bit_field_bonus.h"
# include "threads_bonus.h"
# include "time_bonus.h"

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
 * @param size		Size of the img as int vector. *
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
 * @param img		mlx img struct.
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

// render_init_bonus.c

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
 * @param win_size		Parsed size of window.
 * @return t_err		SUCCESS, ERROR.
 */
t_err	ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, t_vec2i *win_size);

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
t_vec2i	ft_check_screen_size(void *mlx_ptr, t_vec2i win_size);

// render_loop_mlx_bonus.c

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
 * Checks if scene has changed. If so, the scene cur_sample is set to 0.
 * If cur_sample is less than sample_goal, the scene is rendered.
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

// render_sample_bonus.c

/**
 * @brief Raytraces a sample of the scene to the sample buffer.
 *
 * Checks current sample goal. If it is 1, the scene is raytraced
 * without anti-aliasing. If it is more than 1, the scene is raytraced
 * with anti-aliasing.
 * Puts the image to the window.
 * Calcultaes the elapsed time and saves it to the render struct.
 * Increases the current sample number.
 * @param render		Pointer to render struct.
 * @param cur_sample	Pointer to current sample number.
 * @return int			0 if successful, -1 if not.
 */
int			ft_render_sample(t_render *render, uint8_t *cur_sample);

/**
 * @brief Raytraces a single sample of the scene to the sample buffer.
 *
 * Checks if threading is active.
 * If so, it calls ft_raytrace_sample_threaded().
 * If not, it calls ft_raytrace_sample().
 * @param render	Pointer to render struct.
 * @return int		0 if successful, -1 if not.
 */
int			ft_single_sample(t_render *render);

/**
 * @brief Raytraces a sample of the scene and adds it to the sample buffer.
 *
 * Checks if threading is active.
 * If so, it calls ft_add_raytrace_sample_threaded().
 * If not, it calls ft_add_raytrace_sample().
 * Checks if current sample is 1. If so, it calls ft_blend_background().
 * @param render		Pointer to render struct.
 * @param cur_sample	Pointer to current sample number.
 * @return int			0 if successful, -1 if not.
 */
int			ft_anti_alias_sample(t_render *render, uint8_t cur_sample);

// render_draw_bonus.c

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
t_colour	ft_shoot_ray(t_vec2i pos, t_ray ray, t_entities scene, t_cam cam);

/**
 * @brief Raytraces the scene to the sample buffer.
 *
 * Creates rays for each pixel of the image and "shoots" them
 * through the corresponding pixel in the viewport. The colour of
 * each ray is returned and written to the sample buffer.
 * @param render	Pointer to render struct.
 */
void		ft_raytrace_sample(t_render *render);

/**
 * @brief Generate a random vector that is confined within the square
 * surrounding a pixel. The vector lies in the same plane as the viewport.
 *
 * @param pixels		Pixel grid defining its starting position and
 * 						horizontal/vertical distances
 * @return t_vec3
 */
t_vec3		ft_pixel_sample(t_pixel_grid pixels);

/**
 * @brief Constructs a random sample ray for anti-aliasing.
 *
 * Takes the precalculated pixel centre from the camera pixel grid.
 * Ray is constructed in a square surrounding the current pixel
 * Square side length is the distance to the next pixel.
 * Therefore it extends halfway to each neighbouring pixel.
 * Then shoots ray and returns it's colour.
 * @param pos		Position of the pixel in the image.
 * @param ray		Partly build Ray struct.
 * @param scene		Scene struct.
 * @param cam		Camera struct.
 * @return t_colour	Colour of the pixel.
 */
t_colour	ft_shoot_aa_ray(t_vec2i pos, t_ray ray, t_entities scene,
				t_cam cam);

/**
 * @brief Raytraces the scene and adds it to the sample buffer.
 *
 * Works like ft_raytrace_sample(), but the current buffer is not
 * overwritten. The sample is added to it. Then the buffer is
 * divided by the current sample number to get the average colour.
 * Shoots random rays via ft_shoot_aa_ray().
 * @param render	Pointer to render struct.
 */
void		ft_add_raytrace_sample(t_render *render);

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

// render_keyhook_press_bonus.c

/**
 * @brief Handles keypresses.
 *
 * Checks for keypresses and calls the corresponding function.
 * Differentiates between option, bonus, select and manipulation keys.
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

/**
 * @brief Branches to the corresponding manipulation function.
 *
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 */
void		ft_manip_scene(int key, t_render *render);

// render_keyhook_options_bonus.c

/**
 * @brief Handles bonus option keys.
 *
 * 'O': Show options.
 * 'P': Start printing.
 * 'J': Toggle threading.
 * 'K': Toggle anti-aliasing.
 * 'L': Toggle time unit.
 * @param key		Keycode of the pressed key.
 * @param render	Pointer to render struct.
 */
void		ft_change_options_bonus(int key, t_render *render);

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

// render_keyhook_hittable_bonus.c

/**
 * @brief Manipulates the active cone.
 *
 * @param key	Keycode of the pressed key.
 * @param co	Pointer to cone struct.
 * @param inc	Increment value.
 */
void		ft_manip_cone(int key, t_cone *co, float inc);

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
 * Can also use a threaded function to calculate the pixel grid.
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

// render_keyhook_colour.c

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
 * @brief Frees ressources allocated for render.
 *
 * @param render	Pointer to render struct.
 */
void		ft_render_cleanup(t_render *render);

// threads_alt_versions_bonus.c

/**
 * @brief Like ft_raytrace_sample(), but threaded.
 *
 * @param arg		Pointer to thread struct.
 * @return void*	NULL.
 */
void		*ft_raytrace_sample_threaded(void *arg);

/**
 * @brief Like ft_add_raytrace_sample(), but threaded.
 *
 * @param arg		Pointer to thread struct.
 * @return void*	NULL.
 */
void		*ft_add_raytrace_sample_threaded(void *arg);

/**
 * @brief Like ft_blend_background(), but threaded.
 *
 * @param arg		Pointer to thread struct.
 * @return void*	NULL.
 */
void		*ft_blend_background_threaded(void *arg);

/**
 * @brief Like ft_cam_calc_pix_pos(), but threaded.
 *
 * @param arg		Pointer to thread struct.
 * @return void*	NULL.
 */
void		*ft_cam_calc_pix_pos_threaded(void *arg);

// render_output_ppm_bonus.c

/**
 * @brief Outputs the current render as a ppm file.
 *
 * The file is in binary format (P6).
 * Creates a temporary buffer and writes the image to it.
 * @param img		Pointer to mlx img struct.
 * @return t_err	SUCCESS, ERROR.
 */
t_err		ft_output_as_ppm(const t_img img);

// render_output_threaded_bonus.c

/**
 * @brief Wrapper function for threaded output.
 *
 * Calls ft_output_as_ppm() in a detached thread.
 * Then switches the is_printing flag to false.
 * @param arg		Pointer to render struct.
 * @return void*	NULL.
 */
void		*ft_output_threaded(void *arg);

/**
 * @brief Helper function to check is_printing flag.
 *
 * Flag is_printing is protected by a mutex.
 * This function locks the mutex, checks the flag and unlocks the mutex.
 * @param render	Pointer to render struct.
 * @return true		Flag is true.
 * @return false	Flag is false.
 */
bool		ft_is_printing(t_render *render);

/**
 * @brief Helper function to toggle is_printing flag.
 *
 * Flag is_printing is protected by a mutex.
 * This function locks the mutex, toggles the flag and unlocks the mutex.
 * @param render	Pointer to render struct.
 */
void		ft_toggle_is_printing(t_render *render);

#endif
