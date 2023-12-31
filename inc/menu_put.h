/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:31:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/07 12:39:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_PUT_H
# define MENU_PUT_H

/* ====== LIBRARIES ====== */

# include "miniRT_config.h"
# include "render.h"
# include "vec2.h"

/* ====== MACROS ====== */

# define Y_HALF_LINE 10
# define Y_NEXT_LINE 20
# define Y_NEXT_LINE_BIG 30
# define NUMLEN 10

/* ====== TYPEDEFS ====== */

/**
 * @brief Contains info about text for putting on the screen.
 *
 * @param mlx_ptrs	mlx_ptrs struct.
 * @param pos		Position of the text.
 * @param col		Colour of the text.
 */
typedef struct s_putinfo
{
	t_mlx_ptrs	mlx_ptrs;
	t_vec2i		pos;
	uint32_t	col;
}	t_putinfo;

/**
 * @brief Contains info about number to be converted.
 *
 * @param numi		Union as Integer.
 * @param numf		Union as Float.
 * @param pad		Number of spaces to pad.
 * @param prec		Number of digits after the decimal point.
 */
typedef struct s_numinfo
{
	union
	{
		int32_t	numi;
		float	numf;
	};
	uint8_t		pad;
	uint8_t		prec;
}	t_numinfo;

/* ====== FUNCTIONS ====== */

// menu_put_str_num.c

/**
 * @brief Wrapper for mlx_string_put().
 *
 * @param put	t_putinfo struct.
 * @param str	String to be put on the screen.
 */
void	ft_put_str(t_putinfo put, char *str);

/**
 * @brief Converts integer to string and puts it on the screen.
 *
 * Padding can be specified in numinfo.
 * @param put 		t_putinfo struct.
 * @param numinfo	t_numinfo struct.
 */
void	ft_put_int(t_putinfo put, t_numinfo numinfo);

/**
 * @brief Converts float to string and puts it on the screen.
 *
 * Padding and precision can be specified in numinfo.
 * @param put 		t_putinfo struct.
 * @param numinfo	t_numinfo struct.
 */
void	ft_put_float(t_putinfo put, t_numinfo numinfo);

// menu_put_utils.c

/**
 * @brief Puts a 3D point on the screen.
 *
 * For each coordinate (x, y, z) writes the name of the coordinate and the
 * value of the coordinate, with 5 digits padding and 2 digits
 * after the decimal point. Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param name		Name of the point.
 * @param put		t_putinfo struct.
 * @param point		Point to be put on screen.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_3d_point(char *name, t_putinfo put, t_vec3 point);

/**
 * @brief Puts a unit vector on the screen.
 *
 * For each coordinate (x, y, z) writes the name of the coordinate and the
 * value of the coordinate, with 2 digits padding and 5 digits
 * after the decimal point. Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param name		Name of the vector.
 * @param put		t_putinfo struct.
 * @param vec		Unit vector to be put on screen.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_unit_vec(char *name, t_putinfo put, t_vec3 vec);

/**
 * @brief Puts a colour on the screen.
 *
 * For each colour value (r, g, b) writes the name of the value and the
 * value, with 2 digits padding. Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param colour	Colour to be put on screen.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_colour(t_putinfo put, t_colour colour);

/**
 * @brief Puts a single float value on the screen.
 *
 * Writes the value with 5 digits padding and 2 digits
 * after the decimal point. Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param name		Name of the value.
 * @param put		t_putinfo struct.
 * @param value		Float value to be put on screen.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_single_float_value(char *name, t_putinfo put, float value);

// menu_put_hittable.c

/**
 * @brief Puts hittable info on the screen.
 *
 * Writes the id and type of the hittable.
 * Then calls the appropriate function for the hittable type.
 * @param put		t_putinfo struct.
 * @param hittable	Hittable to be put on screen.
 */
void	ft_put_hittable(t_putinfo put, t_hittable hittable);

/**
 * @brief Puts sphere info on the screen.
 *
 * Writes the centre, diameter and colour of the sphere.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param sp		Sphere to be put on screen.
 */
void	ft_put_sp(t_putinfo put, t_sphere sp);

/**
 * @brief Puts plane info on the screen.
 *
 * Writes the point, normal and colour of the plane.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param pl		Plane to be put on screen.
 */
void	ft_put_pl(t_putinfo put, t_plane pl);

/**
 * @brief Puts cylinder info on the screen.
 *
 * Writes the centre, axis, diameter, height and colour of the cylinder.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param cy		Cylinder to be put on screen.
 */
void	ft_put_cy(t_putinfo put, t_cylinder cy);

// menu_put_cam_light.c

/**
 * @brief Puts camera info on the screen.
 *
 * Writes the centre, view direction and FOV of the camera.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param cam		Camera to be put on screen.
 */
void	ft_put_cam(t_putinfo put, t_cam cam);

/**
 * @brief Puts ambient info on the screen.
 *
 * Writes the brightness and colour of the ambient light.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param ambient	Ambient light to be put on screen.
 */
void	ft_put_ambient(t_putinfo put, t_light ambient);

/**
 * @brief Puts light info on the screen.
 *
 * Writes the position, brightness and colour of the light.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param light		Light to be put on screen.
 */
void	ft_put_light(t_putinfo put, t_light light);

// menu_put_general_info.c

/**
 * @brief Puts the current control mode on the screen.
 *
 * Is printed bold.
 * Control mode is always at the top of the menu.
 * @param put		t_putinfo struct.
 * @param mode		Current control mode.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_mode(t_putinfo put, t_mode mode);

/**
 * @brief Puts generic info on the screen.
 *
 * Switch mode, show controls, close menu, print scene, exit.
 * Generic info is always at the bottom of the menu.
 * @param put
 * @return t_vec2i
 */
t_vec2i	ft_put_info(t_putinfo put);

/**
 * @brief Puts the ID of a hittable or a light on the screen.
 *
 * ID is printed bold.
 * @param put		t_putinfo struct.
 * @param id		ID of the hittable or light.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_id(t_putinfo put, int id);

/**
 * @brief Puts the type of a hittable or a light on the screen.
 *
 * @param put		t_putinfo struct.
 * @param type		Type of the hittable or light.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_type(t_putinfo put, t_type type);

// menu_put_utils_ctrl.c

/**
 * @brief Puts control scheme for movement on the screen.
 *
 * @param put		t_putinfo struct.
 * @param name		Name of the vector to move.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_move(t_putinfo put, char *name);

/**
 * @brief Puts control scheme for rotation on the screen.
 *
 * @param put		t_putinfo struct.
 * @param name		Name of the vector to rotate.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_rot(t_putinfo put, char *name);

/**
 * @brief Puts control scheme for incrementing and decrementing
 * a value on the screen.
 *
 * If first true: Shows R and F as control buttons.
 * If first false: Shows T and G as control buttons.
 * @param put		t_putinfo struct.
 * @param name		Name of the value to increment or decrement.
 * @param first		Whether this is first version of control scheme.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_inc_dec(t_putinfo put, char *name, bool first);

// menu_put_hittable_ctrl.c

/**
 * @brief Puts control scheme for hittable on the screen.
 *
 * Writes the id and type of the hittable.
 * Then calls the appropriate function for the hittable type.
 * @param put		t_putinfo struct.
 * @param hittable	Hittable to be put on screen.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_hittable(t_putinfo put, t_hittable hittable);

/**
 * @brief Puts control scheme for sphere on the screen.
 *
 * Control for move, inc/dec diameter and change colour of the sphere.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_sp(t_putinfo put);

/**
 * @brief Puts control scheme for plane on the screen.
 *
 * Control for move, rotate, and change colour of the plane.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_pl(t_putinfo put);

/**
 * @brief Puts control scheme for cylinder on the screen.
 *
 * Control for move, rotate, inc/dec diameter, inc/dec height and change
 * colour of the cylinder.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_cy(t_putinfo put);

// menu_put_cam_light_ctrl.c

/**
 * @brief Puts control scheme for camera on the screen.
 *
 * Control for move, rotate and inc/dec FOV of the camera.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_cam(t_putinfo put);

/**
 * @brief Puts control scheme for light on the screen.
 *
 * Differentiates between ambient and other lights with active.
 * Control for inc/dec brightness and change colour of the ambient light.
 * Control for move, inc/dec brightness and change colour of the other lights.
 * Separated by Y_NEXT_LINE and Y_NEXT_LINE_BIG.
 * @param put		t_putinfo struct.
 * @param active	ID of the passed light.
 * @return t_vec2i	Next position of text.
 */
t_vec2i	ft_put_ctrl_light(t_putinfo put, uint32_t active);

// menu_put_page.c

/**
 * @brief Puts a scene page on the screen.
 *
 * Differentiates between normal and control mode.
 * @param put		t_putinfo struct.
 * @param cur_page	Current page.
 * @return t_vec2i	Next position of text.
 */
void	ft_put_page_scene(t_putinfo put, t_hittable active, t_pages cur_page);

/**
 * @brief Puts an ambient page on the screen.
 *
 * Differentiates between normal and control mode.
 * @param put		t_putinfo struct.
 * @param cur_page	Current page.
 * @return t_vec2i	Next position of text.
 */
void	ft_put_page_ambient(t_putinfo put, t_light ambient, t_pages cur_page);

/**
 * @brief Puts a light page on the screen.
 *
 * Differentiates between normal and control mode.
 * @param put		t_putinfo struct.
 * @param cur_page	Current page.
 * @return t_vec2i	Next position of text.
 */
void	ft_put_page_light(t_putinfo put, t_light light, t_pages cur_page);

/**
 * @brief Puts a camera page on the screen.
 *
 * Differentiates between normal and control mode.
 * @param put		t_putinfo struct.
 * @param cur_page	Current page.
 * @return t_vec2i	Next position of text.
 */
void	ft_put_page_cam(t_putinfo put, t_cam cam, t_pages cur_page);

#endif