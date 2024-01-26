/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:45 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/26 12:04:27 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdio.h>
# include <fcntl.h>				// req for open()
# include <unistd.h>			// req for read(), write(), close()

// Home-grown libs
# include "ft_print.h"
# include "camera.h"

# if IS_BONUS
#  include "parse_bonus.h"
#  include "render_bonus.h"
# else
#  include "parse.h"
#  include "render.h"
# endif

#endif
