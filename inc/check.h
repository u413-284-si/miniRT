/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:37:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 11:48:51 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

/* ====== LIBRARIES ====== */

# include "error_type.h"
# include "error_msg.h"
# include "ft_char.h"
# include "ft_strtod.h"
# include "entities.h"
# include "miniRT_config.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

// check.c

/**
 * @brief Check array of imported lines.
 *
 * Loop through lines array:
 * - Check the type of a line with ft_check_line_type().
 * - Increment entity counter with ft_incr_ent_count().
 * - If ERROR print line number.
 * After loop check entity count with ft_check_entity_count().
 * Set the provided ints with the calculated values.
 * @param lines Array of imported lines.
 * @param lsrc_count Count of found entities light.
 * @param total Count of found entities sphere + plane + cylinder.
 * @return t_err ERROR if any subfunction fails.
 */
t_err		ft_check_lines(char **lines, int *lsrc_count, int *total);

/**
 * @brief Dispatch function for different line types.
 *
 * Searches line for entity identifier.
 * If found calls and returns correct check function.
 * If not returns UNKNOWN.
 * @param line Line to check for identifier.
 * @return t_type Specific entity type if correct, else UNKOWN.
 */
t_type	ft_check_line_type(char *line);

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
t_err		ft_incr_ent_count(int ent_count[SUM_ENTS], t_type ent_type);

/**
 * @brief Check if minimum number of specific entities was found.
 *
 * Following types need at least one:
 * - Ambient light,
 * - Camera,
 * - Light
 * Since its possible to have scene without shapes, this is not seen as error.
 * @param ent_count Array with counts for all entities.
 * @return t_err ERROR if minimum number of an entity is not found.
 */
t_err		ft_check_entity_count(int ent_count[SUM_ENTS]);

// check_line.c

/**
 * @brief Moves line one space forward and sanitizes spaces.
 *
 * Move line forward if space ' ' is encountered.
 * Search for first non-space char.
 * Shift line to left by copying it, getting rid of spaces.
 * Sanitizes spaces to only one space between numbers.
 * @param line Pointer to current line.
 */
void		ft_rm_space(char **line);

/**
 * @brief Tries to convert str to float and checks range.
 *
 * Line gets converted with ft_strtod().
 * Error if conversion fails.
 * Error if number is out of range.
 * Error if number is not followed by correct separator.
 * Correct separator can be controlled by passed bool: ',' or ' ' and '\0'.
 * If conversion is successful, the line gets moved forward.
 * @param line Pointer to current line.
 * @param min Minimum value for converted number.
 * @param max Maximum value for converted number.
 * @param comma Controls if separator should be ',' or ' ' and '\0'.
 * @return true Float is valid.
 * @return false Conversion failed, out of range, wrong separator.
 */
bool		ft_isvalid_float(char **line, float min, float max, bool comma);

/**
 * @brief Checks three floats, separated by ','.
 *
 * Tries to convert three floats (block) with ft_isvalid_float_block().
 * @param line Pointer to current line.
 * @param min Minimum value for converted number.
 * @param max Maximum value for converted number.
 * @return true Block is valid.
 * @return false Block is not valid.
 */
bool		ft_isvalid_float_block(char **line, float min, float max);

/**
 * @brief Tries to convert str into rgb int and checks range.
 *
 * Error if str does not start with digit
 * (prevents negative numbers and wrong chars).
 * Convert digits as long as value below 255 and moves line forward.
 * Error if number is bigger than 255.
 * Error if number is not followed by correct separator.
 * Correct separator can be controlled by passed bool: ',' or ' ' and '\0'.
 * @param line Pointer to current line.
 * @param comma Controls if separator should be ',' or ' ' and '\0'.
 * @return true Number is valid.
 * @return false Wrong beginning char, out of range, wrong separator.
 */
bool		ft_isvalid_rgb_val(char **line, bool comma);

/**
 * @brief Checks three rgb values, separated by ','.
 *
 * Tries to convert three numbers (Block) with ft_isvalid_rgb_val().
 * @param line Pointer to current line.
 * @return true Block is valid.
 * @return false Block is not valid.
 */
bool		ft_isvalid_rgb_block(char **line);

// check_entity1.c

/**
 * @brief Checks if ambient light line is correct.
 *
 * Function gets called if line has identifier "A".
 * Check if following is true:
 * - ambient lighting ratio in range [0.0,1.0].
 * - R,G,B colors in range [0-255].
 * @param line Pointer to current line.
 * @return t_type AMBIENT on success, UNKNOWN if fail.
 */
t_type	ft_check_ambient(char *line);

/**
 * @brief Checks if camera line is correct.
 *
 * Function gets called if line has identifier "C".
 * Check if following is true:
 * - x,y,z coordinates of the view point.
 * - 3d normalized orientation vector. In range [-1,1] for each x,y,z axis.
 * - FOV : Horizontal field of view in degrees in range [0,180].
 * @param line Pointer to current line.
 * @return t_type CAMERA on success, UNKNOWN if fail.
 */
t_type	ft_check_camera(char *line);

/**
 * @brief Checks if light line is correct.
 *
 * Function gets called if line has identifier "L".
 * Check if following is true:
 * - x,y,z coordinates of the light point.
 * - the light brightness ratio in range [0.0,1.0].
 * - R,G,B colors in range [0-255].
 * @param line Pointer to current line.
 * @return t_type LIGHT on success, UNKNOWN if fail.
 */
t_type	ft_check_light(char *line);

// check_entity2.c

/**
 * @brief Checks if sphere line is correct.
 *
 * Function gets called if line has identifier "sp".
 * Check if following is true:
 * - x,y,z coordinates of the sphere center.
 * - the sphere diameter.
 * - R,G,B colors in range [0-255].
 * @param line Pointer to current line.
 * @return t_type SPHERE on success, UNKNOWN if fail.
 */
t_type	ft_check_sphere(char *line);

/**
 * @brief Checks if plane line is correct.
 *
 * Function gets called if line has identifier "pl".
 * Check if following is true:
 * - x,y,z coordinates of a point in the plane.
 * - 3d normalized normal vector. In range [-1,1] for each x,y,z axis.
 * - R,G,B colors in range [0-255].
 * @param line Pointer to current line.
 * @return t_type PLANE on success, UNKNOWN if fail.
 */
t_type	ft_check_plane(char *line);

/**
 * @brief Checks if cylinder line is correct.
 *
 * Function gets called if line has identifier "cy".
 * Check if following is true:
 * - x,y,z coordinates of the center of the cylinder.
 * - 3d normalized axis vector of cylinder. In range [-1,1] for each x,y,z axis.
 * - the cylinder diameter.
 * - the cylinder height.
 * - R,G,B colors in range [0,255].
 * @param line Pointer to current line.
 * @return t_type CYLINDER on success, UNKNOWN if fail.
 */
t_type	ft_check_cylinder(char *line);

#endif