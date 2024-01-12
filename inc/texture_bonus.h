/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:07:37 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/12 20:34:40 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <math.h>

// Home-grown libs
# include "hit_manager_bonus.h"

/* ====== FUNCTIONS ====== */

/**
 * @brief Applies checker texture unto hittable
 * 
 * @param rec	Hit record containing data on hit point 
 */
void	ft_apply_checker_texture(t_hitrecord *rec);

#endif
