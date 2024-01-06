/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:07:37 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/04 15:32:19 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <math.h>

// Home-grown libs
# include "structs_bonus.h"

/* ====== FUNCTIONS ====== */

/**
 * @brief Applies checker texture unto hittable
 * 
 * @param rec	Hit record containing data on hit point 
 */
void	ft_apply_checker_texture(t_hitrecord *rec);


float	ft_set_tiling(const float uv, const float scale);


#endif
