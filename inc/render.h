/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:18:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/26 08:59:37 by gwolf            ###   ########.fr       */
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
# include "entities.h"

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
t_err	ft_init_renderer(t_render *render, t_image *screen, bool fullscreen);
t_err	ft_init_image(t_render *render, int size[2]);
void	ft_set_fullscreen(t_render *render, t_image *screen);

// render_keyhook.c
int	ft_keyhook_press(int key, t_render *render);

// render_draw.c
void	ft_put_pix_to_image(t_buffer *img, int x, int y, int color);

t_err	ft_output_as_ppm(int *img_arr, int width, int height);

// render_put_num_utils.c
int	ft_count_digit(int num);
void	ft_str_rev(char *str);
void	ft_ftoa_in_place(float num, char *str, int precision);
int	ft_itoa_in_place(int num, char *str);

// render_put_num.c
void	ft_mlx_put_float(t_render *render, int pos[2], float num, int prec);
void	ft_mlx_put_int(t_render *render, int pos[2], int num, int pad);

#endif