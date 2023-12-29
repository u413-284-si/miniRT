/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:22:00 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/29 18:48:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H


/**
 * @brief Represents a tridimensional vector
 * @param x	The x coordinate
 * @param y	The y coordinate
 * @param z	The z coordinate
 */
typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

/**
 * @brief Represents a fourdimensional vector
 * @param x		The x coordinate
 * @param y		The y coordinate
 * @param z		The z coordinate
 * @param one	4th component with value 1
 */
typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	one;
}	t_vec4;

/**
 * @brief Represents a ray
 * @param origin	point of ray origin
 * @param direction	vector of ray direction
 * @param d			distance into ray direction
 */
typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	float	d;
}	t_ray;

/**
 * @brief Represents an RGB colour with float values from 0.0 - 1.0
 * @param r		Red component
 * @param g		Green component
 * @param b		Blue component
 */
typedef struct s_colour
{
	float	r;
	float	g;
	float	b;
}	t_colour;

/**
 * @brief Shows point of intersection
 * 
 * @param ray				Intersecting ray
 * @param point				Point of intersection
 * @param normal			Normal vector at point of intersection
 * @param axis_hit			Point of intersection with a cylinders axis
 * @param d					Distance into ray direction when point is hit
 * @param colour			Colour of object at intersection
 * @param shininess			Material property of point of intersection
 * 							on the breadth of the angle of specular reflection 
 * 							(the higher, the smoother the surface appears)
 * @param reflectivity		Material property of point of intersection
 * 							on share of reflected light 
 * @param reflection_count	Amount of reflections performed
 */
typedef struct s_hitrecord
{
	t_ray		ray;
	t_vec3		point;
	t_vec3		normal;
	t_vec3		axis_hit;
	float		d;
	t_colour	colour;
	float		shininess;
	float		reflectivity;
	int			reflection_count;
}	t_hitrecord;

/**
 * @brief Contains camera parameters
 * 
 * @param look_from				Position the camera is looking from
 * @param look_at				Position the camera is looking at
 * @param u						Basis vector pointing to camera right
 * @param v						Basis vector pointing to camera up
 * @param w						Basis vector pointing to opposite view direction
 * @param vup					Camera-relative up direction
 * @param camera_centre			Camera position
 * @param camera_direction		Direction of camera view
 * @param hfov					Horizontal field of view in degrees
 */

typedef struct s_cam
{
	t_vec3	look_from;
	t_vec3	look_at;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	t_vec3	vup;
	t_vec3	camera_centre;
	t_vec3	camera_direction;
	float	hfov;
}	t_cam;

/**
 * @brief Contains viewport parameters
 * 
 * The viewport is a virtual rectangle in the 3D world containing the grid
 * of image pixel locations. If pixels are equispaced horizontally and verti-
 * cally, the viewport has the same aspect_ratio as the image.
 * The focal length is the distance between the camera centre and the viewport
 * centre (vector orthogonal on viewport plane).
 * @param viewport_width		Width of viewport rectangle
 * @param viewport_height		Height of viewport rectangle
 * @param focal_length			Distance between camera centre and viewport centre
 * @param viewport_u			Vector u in viewport coordinates (= x)
 * @param viewport_v			Vector v in viewport coordinates (= -y)
 * @param delta_u				Distance between two pixels in u-direction
 * @param delta_v				Distance between two pixels in v-direction
 * @param viewport_upper_left	Position of upper left corner of viewport
 * @param pixel00_pos			Position of the first pixel (0, 0)
 */
typedef struct s_viewport
{
	float	viewport_width;
	float	viewport_height;
	float	focal_length;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	delta_u;
	t_vec3	delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_pos;
}	t_viewport;

/**
 * @brief Interval of accepted values
 * 
 * @param min	Minimum of interval
 * @param max 	Maximum of interval
 */
typedef struct s_interval
{
	float	min;
	float	max;
}	t_interval;

/**
 * @brief Contains factors to solve linear and quadratic equations.
 * 
 * ax² + bx + c = 0
 * 
 * x = (-b +/- sqr(b² - 4ac)) / 2a
 * Here we use d instead of x as variable to represent the distance of the
 * ray traveled.
 * @param a		Factor of quadratic component
 * @param b		Factor of linear component
 * @param c		Constant
 * @param d1	First solution 
 * @param d2	Second solution
 */
typedef struct s_equation
{
	float	a;
	float	b;
	float	c;
	float	d1;
	float	d2;
}	t_equation;

#endif
