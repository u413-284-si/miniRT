/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:14:05 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 16:19:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_H
# define MANIP_H

/* ====== LIBRARIES ====== */

# if IS_BONUS
#  include "render_struct_bonus.h"
# else
# 	include "render_struct.h"
# endif

/* ====== MACROS ========*/

# define NUM_COLOURS 9
# define NUM_RAINBOW_COLOURS 7

/* ====== TYPEDEF ========*/

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

#endif
