/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:33 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/19 23:15:08 by gwolf            ###   ########.fr       */
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
# include "entities.h"
# include "key_codes.h"

/* ====== TYPEDEFS ====== */

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bytes;
}	t_img;

typedef struct s_mlx_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx_ptrs;

typedef struct s_render
{
	t_mlx_ptrs	mlx_ptrs;
	t_cam		cam;
	t_entities	scene;
	t_image		image;
	t_viewport	vp;
}	t_render;

/* ====== FUNCTIONS ====== */

// render_init.c
t_err	ft_init_mlx_ptrs(t_mlx_ptrs *mlx_ptrs, t_image *image, bool fullscreen);
t_err	ft_init_image(t_mlx_ptrs *mlx_ptrs, int size[2]);
void	ft_set_fullscreen(t_mlx_ptrs *mlx_ptrs, t_image *image);

// render_draw.c
void	ft_put_pix_to_image(t_img *img, int x, int y, int color);
void	ft_render_image(t_render render);

// render_output_ppm.c
t_err	ft_output_as_ppm(int *img_arr, int width, int height);

// render_keyhook.c
int		ft_keyhook_press(int key, t_render *render);

// render_loop_mlx.c
void	ft_render_start_loop(t_render *render);

// render_output_ppm.c
t_err	ft_output_as_ppm(int *img_arr, int width, int height);

#endif