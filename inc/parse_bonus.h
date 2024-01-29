/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:03:19 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 14:20:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

/* ====== LIBRARIES ====== */

# include "parse.h"

# include "entities_bonus.h"

/* ====== FUNCTIONS ====== */

// import from check_bonus.h
t_err	ft_check_lines_bonus(char **lines, int *lsrc_c, int *total);

// parse_bonus.c

/**
 * @brief Chooses the correct checker function depending on bool is_bonus.
 *
 * @param lines		Imported file in sanitized array.
 * @param lsrc_c	Count of found entities light.
 * @param total		Count of found entities sphere + plane + cylinder.
 * @param is_bonus	True if file has "#bonus" in first line.
 * @return t_err	ERROR if subfunction fails.
 */
t_err	ft_choose_check_ft(char **lines, int *lsrc_c, int *total,
			bool is_bonus);

/**
 * @brief Initialises the bonus parameters of all entities
 * to zero when reading a base file
 *
 * Bonus parameters:
 * - Shininess
 * - Reflectivity
 * - Checkered
 * @param scene Where entities are stored.
 */
void	ft_initialise_non_parsed(t_entities *scene);

/**
 * @brief Dispatcher for different parsing functions
 *
 * Loops through lines and saves them according to their identifier.
 * Keeps track of lights and id to correctly address array index.
 * @param lines		Imported file in sanitized array.
 * @param scene		Where entities are stored.
 * @param cam		Camera used in program.
 * @param win_size	Window size.
 */
void	ft_parse_lines_bonus(char **lines, t_entities *scene, t_cam *cam,
			t_vec2i *win_size);

// parse_entity_sp_pl_cy_bonus.c

/**
 * @brief Parse sphere line.
 *
 *Function gets called if line has identifier "sp".
 * Parse the following:
 * - x,y,z coordinates of the sphere center.
 * - the sphere diameter.
 * - the shininess.
 * - the reflectivity.
 * - whether it's checkered.
 * - R,G,B colors in range [0-255].
 * Also sets type and id.
 * @param line		Pointer to current line.
 * @param sphere	Struct where to save.
 * @param id		Current shape id.
 */
void	ft_parse_sphere_bonus(char *line, t_hittable *sphere, size_t id);

/**
 * @brief Parse plane line.
 *
 * Function gets called if line has identifier "pl".
 * Parse the following:
 * - x,y,z coordinates of a point in the plane.
 * - 3d normalized normal vector. In range [-1,1] for each x,y,z axis.
 * - the shininess.
 * - the reflectivity.
 * - whether it's checkered.
 * - R,G,B colors in range [0-255].
 * Also sets type and id.
 * @param line	Pointer to current line.
 * @param plane	Struct where to save.
 * @param id	Current shape id.
 */
void	ft_parse_plane_bonus(char *line, t_hittable *plane, size_t id);

/**
 * @brief Parse cylinder line.
 *
 * Function gets called if line has identifier "cy".
 * Parse the following:
 * - x,y,z coordinates of the center of the cylinder.
 * - 3d normalized axis vector of cylinder. In range [-1,1] for each x,y,z axis.
 * - the cylinder diameter.
 * - the cylinder height.
 * - the shininess.
 * - the reflectivity.
 * - whether it's checkered.
 * - R,G,B colors in range [0,255].
 * Also sets type and id.
 * @param line		Pointer to current line.
 * @param cylinder	Struct where to save.
 * @param id		Current shape id.
 */
void	ft_parse_cylinder_bonus(char *line, t_hittable *cylinder, size_t id);

/**
 * @brief Parse cone line.
 *
 * Function gets called if line has identifier "co".
 * Parse the following:
 * - x,y,z coordinates of the apex of the cone.
 * - 3d normalized axis vector of cone. In range [-1,1] for each x,y,z axis.
 * - the cone radius.
 * - the cone height.
 * - the shininess.
 * - the reflectivity.
 * - whether it's checkered.
 * - R,G,B colors in range [0,255].
 * Also sets type and id.
 * @param line		Pointer to current line.
 * @param cone		Struct where to save.
 * @param id		Current shape id.
 */
void	ft_parse_cone_bonus(char *line, t_hittable *cone, size_t id);

// parse_line.c

/**
 * @brief Parses a single int.
 *
 * Moves the line forward.
 * @param line	Pointer to current position of line.
 * @param var	Variable where to save.
 */
void	ft_parse_int(char **line, int *var);

// parse_win_size_bonus.c

/**
 * @brief Parse window size line.
 *
 * @param line		Pointer to current line.
 * @param win_size	Struct where to save.
 */
void	ft_parse_win_size(char *line, t_vec2i *win_size);

#endif
