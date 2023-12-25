/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:03:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 11:49:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

/* ====== LIBRARIES ====== */

# include "error_syscall_bonus.h"
# include "cleanup_bonus.h"
# include "ft_strtod.h"
# include "entities_bonus.h"
# include "camera_bonus.h"

/* ====== FUNCTIONS ====== */

// import from import_file.h
t_err	ft_import_file(char *filename, char ***lines);

// import from check.h
t_err	ft_check_lines(char **lines, int *lsrc_c, int *total);

// parse.c

/**
 * @brief Imports, checks, and parses the provided file.
 *
 * Import with ft_import_file().
 * Check with ft_check_lines().
 * Allocate memory with ft_malloc_ents().
 * Parse with ft_parse_lines().
 * @param filename	Provided filename.
 * @param scene		Where entities are stored.
 * @param cam		Camera used in program.
 * @return t_err SUCCESS, ERROR if subfunction fails.
 */
t_err	ft_parse_file(char *filename, t_entities *scene, t_cam *cam);

/**
 * @brief Allocates memory for lights and hittable array.
 *
 * @param lsrc		Pointer to light array.
 * @param obj		Pointer to hittable array.
 * @param lsrc_c	Sum of all lights excluding ambient.
 * @param total		Sum of all shapes (sphere, plane, cylinder)
 * @return t_err ERROR if malloc() fails.
 */
t_err	ft_malloc_ents(t_light **lsrc, t_hittable **obj, int lsrc_c, int total);

/**
 * @brief Dispatcher for different parsing functions
 *
 * Loops through lines and saves them according to their identifier.
 * Keeps track of lights and id to correctly address array index.
 * @param scene 	Where entities are stored.
 * @param cam	Camera used in program.
 * @param lines	Imported file in sanitized array.
 */
void	ft_parse_lines(t_entities *scene, t_cam *cam, char **lines);

// parse_entity1.c

/**
 * @brief Parse ambient light line.
 *
 * Function gets called if line has identifier "A".
 * Parse the following:
 * - ambient lighting ratio in range [0.0,1.0].
 * - R,G,B colors in range [0-255].
 * @param line		Pointer to current line.
 * @param ambient	Struct where to save.
 */
void	ft_parse_ambient(char *line, t_light *ambient);

/**
 * @brief Parse camera line.
 *
 * Function gets called if line has identifier "C".
 * Parse the following:
 * - x,y,z coordinates of the view point.
 * - 3d normalized orientation vector. In range [-1,1] for each x,y,z axis.
 * - FOV : Horizontal field of view in degrees in range [0,180].
 * @param line	Pointer to current line.
 * @param cam	Struct where to save.
 */
void	ft_parse_camera(char *line, t_cam *cam);

/**
 * @brief Parse light line.
 *
 * Function gets called if line has identifier "L".
 * Parse the following:
 * - x,y,z coordinates of the light point.
 * - the light brightness ratio in range [0.0,1.0].
 * - R,G,B colors in range [0-255].
 * @param line	Pointer to current line.
 * @param light	Struct where to save.
 */
void	ft_parse_light(char *line, t_light *light);

// parse_entity2.c

/**
 * @brief Parse sphere line.
 *
 *Function gets called if line has identifier "sp".
 * Parse the following:
 * - x,y,z coordinates of the sphere center.
 * - the sphere diameter.
 * - R,G,B colors in range [0-255].
 * Also sets type and id.
 * @param line		Pointer to current line.
 * @param sphere	Struct where to save.
 * @param id		Current shape id.
 */
void	ft_parse_sphere(char *line, t_hittable *sphere, size_t id);

/**
 * @brief Parse plane line.
 *
 * Function gets called if line has identifier "pl".
 * Parse the following:
 * - x,y,z coordinates of a point in the plane.
 * - 3d normalized normal vector. In range [-1,1] for each x,y,z axis.
 * - R,G,B colors in range [0-255].
 * Also sets type and id.
 * @param line	Pointer to current line.
 * @param plane	Struct where to save.
 * @param id	Current shape id.
 */
void	ft_parse_plane(char *line, t_hittable *plane, size_t id);

/**
 * @brief Parse cylinder line.
 *
 * Function gets called if line has identifier "cy".
 * Parse the following:
 * - x,y,z coordinates of the center of the cylinder.
 * - 3d normalized axis vector of cylinder. In range [-1,1] for each x,y,z axis.
 * - the cylinder diameter.
 * - the cylinder height.
 * - R,G,B colors in range [0,255].
 * Also sets type and id.
 * @param line		Pointer to current line.
 * @param cylinder	Struct where to save.
 * @param id		Current shape id.
 */
void	ft_parse_cylinder(char *line, t_hittable *cylinder, size_t id);

// parse_line.c

/**
 * @brief Parses values of a rgb colour block.
 *
 * Needs a correctly formatted block: Digits separated by a comma.
 * Moves the line forward.
 * @param line		Pointer to current position of line.
 * @param colour	Struct where to save.
 */
void	ft_parse_colour_block(char **line, t_colour *colour);

/**
 * @brief Parse a single float.
 *
 * Float must be correctly formatted (12 or 34.56)
 * Moves the line forward.
 * @param line	Pointer to current position of line.
 * @param var	Variable where to save.
 */
void	ft_parse_float(char **line, float *var);

/**
 * @brief Parse values of a float block.
 *
 * Needs a correctly formatted block: Floats separated by a comma.
 * Calls ft_parse_float() three times.
 * Moves the line forward.
 * @param line	Pointer to current position of line.
 * @param vec3	Struct where to save.
 */
void	ft_parse_float_block(char **line, t_vec3 *vec3);

#endif