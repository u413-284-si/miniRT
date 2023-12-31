/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:57:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/31 11:08:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MENU_H
# define RENDER_MENU_H

/* ====== LIBRARIES ====== */

# include "render.h"
# include "vec2.h"

/* ====== MACROS ====== */

# define NUMLEN 10
# define BOLD "-schumacher-*-bold-r-normal-*-*-160-*-*-*-*-*-*"
# define REGULAR "-schumacher-*-medium-r-normal-*-*-160-*-*-*-*-*-*"
# define Y_NEXT_LINE 20
# define Y_NEXT_LINE_BIG 30
# define X_OFFSET 30
# define X_OFFSET_BIG 70
# define WHITE 0xffffff
# define MENU_WIDTH 150

/* ====== TYPEDEFS ====== */

typedef struct s_numinfo
{
	union
	{
		int32_t	numi;
		float	numf;
	};
	uint8_t		pad;
	uint8_t		prec;
	uint32_t	col;
}	t_numinfo;

/* ====== FUNCTIONS ====== */

// menu_init.c

void	ft_init_menu(t_menu *menu, uint8_t alpha, uint32_t colour, uint32_t font_col);

// menu_put_num.c

void	ft_mlx_put_str(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			char *str);
void	ft_mlx_put_int(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_numinfo numinfo);
void	ft_mlx_put_float(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_numinfo numinfo);

// menu_put_element.c

t_vec2i	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_vec3 point);
t_vec2i	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_vec3 vec);
t_vec2i	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_colour colour);
t_vec2i	ft_put_float_value(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			float value);

// menu_put_hittable.c

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_hittable hittable);
void	ft_put_sphere(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_sphere sp);
void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_plane pl);
void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_cylinder cy);

// menu_put_camera_lights.c

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_cam cam);
void	ft_put_light(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col,
			t_light light);

// menu_draw.c
uint32_t	fast_alpha_blend(uint32_t bg_color, t_menu menu);
void	ft_blend_background(t_img *img, int x, int y, t_menu menu);
void	ft_draw_menu(t_render *render);

#endif