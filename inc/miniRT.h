/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:45 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/28 15:46:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ====== LIBRARIES ====== */

# if IS_BONUS
#  include "parse_bonus.h"
#  include "render_bonus.h"
# else
#  include "parse.h"
#  include "render.h"
# endif

#endif
