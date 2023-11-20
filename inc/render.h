/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:18:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 23:04:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/* ====== LIBRARIES ====== */

# include <mlx.h>
# include <X11/X.h>

# include "error_mlx.h"
# include "camera.h"
# include "ft_print.h"
# include "cleanup.h"
# include "key_codes.h"

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

// render_keyhook.c
int	ft_key_hook_press(int key, t_render *render);

// render_loop.c
void	ft_start_mlx_loop(t_render *render, t_image image);

// render_draw.c
void	ft_put_pix_to_image(t_buffer *img, int x, int y, int color);
void	ft_render_image(t_image image, t_cam cam, t_viewport vp, \
	t_entities scene, t_render *render);

t_err	ft_print_image_as_ppm(t_image image, t_buffer buffer);

#endif