/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:18:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 14:51:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/* ====== LIBRARIES ====== */

# include <mlx.h>

# include "error_mlx.h"
# include "camera.h"
# include "ft_print.h"
# include "cleanup.h"

/* ====== TYPEDEFS ====== */

typedef struct s_buffer {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bytes;
}	t_buffer;

typedef struct s_render {
	void		*mlx_ptr;
	void		*win_ptr;
	t_buffer	buffer;
}	t_render;

/* ====== FUNCTIONS ====== */

// render_init.c
t_err	ft_init_window(t_render *render, t_image *screen, bool fullscreen);
t_err	ft_init_image(t_render *render, int size[2]);
void	ft_set_fullscreen(t_render *render, t_image *screen);

#endif