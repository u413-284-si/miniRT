/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:37:46 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 14:14:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H

/* ====== LIBRARIES ====== */

# include "check.h"

# include "entities_bonus.h"
# include "miniRT_config_bonus.h"

/* ====== FUNCTIONS ====== */

// check_bonus.c

/**
 * @brief Check array of imported lines.
 *
 * Loop through lines array:
 * - Check the type of a line with ft_check_line_type_bonus().
 * - Increment entity counter with ft_incr_ent_count_bonus().
 * - If ERROR print line number.
 * After loop check entity count with ft_check_entity_count().
 * Set the provided ints with the calculated values.
 * @param lines Array of imported lines.
 * @param lsrc_count Count of found entities light.
 * @param total Count of found entities sphere + plane + cylinder.
 * @return t_err ERROR if any subfunction fails.
 */
t_err		ft_check_lines_bonus(char **lines, int *lsrc_count, int *total);

/**
 * @brief Dispatch function for different line types.
 *
 * Searches line for entity identifier.
 * If found calls and returns correct check function.
 * If not returns UNKNOWN.
 * @param line Line to check for identifier.
 * @return t_type Specific entity type if correct, else UNKNOWN.
 */
t_type		ft_check_line_type_bonus(char *line);

/**
 * @brief Increase entity count, and check if too many.
 *
 * Has static array to store the maximum for all entity types.
 * Increases the specific entity count depending on passed type.
 * Prints error message if specific max is exceeded.
 * @param ent_count Array with counts for all entities.
 * @param ent_type Specific type which should be increased.
 * @return t_err ERROR if increased count is bigger than specific max.
 */
t_err		ft_incr_ent_count_bonus(int ent_count[SUM_ENTS], t_type ent_type);

// check_entity_sp_pl_cy_bonus.c

/**
 * @brief Checks if sphere line is correct.
 *
 * Function gets called if line has identifier "sp".
 * Check if following is true:
 * - x,y,z coordinates of the sphere center.
 * - the sphere diameter.
 * - the shininess value.
 * - the reflectivity value.
 * - whether it is checkered.
 * - R,G,B colors in range [0-255].
 * @param line Pointer to current line.
 * @return t_type SPHERE on success, UNKNOWN if fail.
 */
t_type		ft_check_sphere_bonus(char *line);

/**
 * @brief Checks if plane line is correct.
 *
 * Function gets called if line has identifier "pl".
 * Check if following is true:
 * - x,y,z coordinates of a point in the plane.
 * - 3d normalized normal vector. In range [-1,1] for each x,y,z axis.
 * - the shininess value.
 * - the reflectivity value.
 * - whether it is checkered.
 * - R,G,B colors in range [0-255].
 * @param line Pointer to current line.
 * @return t_type PLANE on success, UNKNOWN if fail.
 */
t_type		ft_check_plane_bonus(char *line);

/**
 * @brief Checks if cylinder line is correct.
 *
 * Function gets called if line has identifier "cy".
 * Check if following is true:
 * - x,y,z coordinates of the center of the cylinder.
 * - 3d normalized axis vector of cylinder. In range [-1,1] for each x,y,z axis.
 * - the cylinder diameter.
 * - the cylinder height.
 * - the shininess value.
 * - the reflectivity value.
 * - whether it is checkered.
 * - R,G,B colors in range [0,255].
 * @param line Pointer to current line.
 * @return t_type CYLINDER on success, UNKNOWN if fail.
 */
t_type		ft_check_cylinder_bonus(char *line);

/**
 * @brief Checks if cone line is correct.
 *
 * Function gets called if line has identifier "co".
 * Check if following is true:
 * - x,y,z coordinates of the apex of the cone.
 * - 3d normalized axis vector of cone. In range [-1,1] for each x,y,z axis.
 * - the cone radius.
 * - the cone height.
 * - the shininess value.
 * - the reflectivity value.
 * - whether it is checkered.
 * - R,G,B colors in range [0,255].
 * @param line	Pointer to current line.
 * @return t_type CONE on success, UNKNOWN if fail.
 */
t_type		ft_check_cone_bonus(char *line);

// check_win_size_bonus.c

/**
 * @brief Checks if size line is correct.
 *
 * @param line		Pointer to current line.
 * @return t_type	SIZE on success, UNKNOWN if fail
 */
t_type		ft_check_win_size(char *line);

#endif
