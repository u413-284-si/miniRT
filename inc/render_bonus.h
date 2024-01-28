/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 15:59:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

/* ====== LIBRARIES ====== */

# include "render.h"

# include "render_struct_bonus.h"
# include "miniRT_config_bonus.h"
# include "ray_bonus.h"
# include "entities_bonus.h"
# include "threads_bonus.h"
# include "time_bonus.h"
# include "utils_random_bonus.h"

/* ====== FUNCTIONS ====== */

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

// render_keyhook_hittable_bonus.c

/**
 * @brief Manipulates the active cone.
 *
 * @param key	Keycode of the pressed key.
 * @param co	Pointer to cone struct.
 * @param inc	Increment value.
 */
void		ft_manip_cone(int key, t_cone *co, float inc);

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
