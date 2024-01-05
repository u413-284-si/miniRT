/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:57:42 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 15:03:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MENU_H
# define RENDER_MENU_H

/* ====== LIBRARIES ====== */

# include "miniRT_config.h"
# include "render.h"
# include "vec2.h"

/* ====== MACROS ====== */

# define Y_NEXT_LINE 20
# define Y_NEXT_LINE_BIG 30
# define NUMLEN 10

/* ====== TYPEDEFS ====== */

typedef struct s_putinfo
{
	t_vec2i		pos;
	uint32_t	col;
}	t_putinfo;

typedef struct s_numinfo
{
	union
	{
		int32_t	numi;
		float	numf;
	};
	uint8_t		pad;
	uint8_t		prec;
}	t_numinfo;

/* ====== FUNCTIONS ====== */

// menu_put_num.c

void	ft_mlx_put_str(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *str);
void	ft_mlx_put_int(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_numinfo numinfo);
void	ft_mlx_put_float(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_numinfo numinfo);

// menu_put_element.c

t_vec2i	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_vec3 point);
t_vec2i	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_vec3 vec);
t_vec2i	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_colour colour);
t_vec2i	ft_put_float_value(t_mlx_ptrs *mlx_ptrs, t_putinfo put, float value);

// menu_put_hittable.c

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_hittable hittable);
void	ft_put_sphere(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_sphere sp);
void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_plane pl);
void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_cylinder cy);

// menu_put_camera_lights.c

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_cam cam);
void	ft_put_ambient(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_light ambient);
void	ft_put_light(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_light light);

// menu_put_mode.c

t_vec2i	ft_put_mode(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_mode mode);
t_vec2i	ft_put_info(t_mlx_ptrs *mlx_ptrs, t_putinfo put);
t_vec2i	ft_put_id(t_mlx_ptrs *mlx_ptrs, t_putinfo put, int id);
t_vec2i	ft_put_type(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_type type);

// menu_put_ctrl_base.c

t_vec2i	ft_put_ctrl_move(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name);
t_vec2i	ft_put_ctrl_rot(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name);
t_vec2i	ft_put_ctrl_inc_dec_1(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name);
t_vec2i	ft_put_ctrl_inc_dec_2(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *name);

// menu_put_ctrl_hittable.c

t_vec2i	ft_put_ctrl_hittable(t_mlx_ptrs *mlx_ptrs, t_putinfo put,
			t_hittable *hittable);
t_vec2i	ft_put_ctrl_sp(t_mlx_ptrs *mlx_ptrs, t_putinfo put);
t_vec2i	ft_put_ctrl_pl(t_mlx_ptrs *mlx_ptrs, t_putinfo put);
t_vec2i	ft_put_ctrl_cy(t_mlx_ptrs *mlx_ptrs, t_putinfo put);

// menu_put_ctrl_cam_lights.c
t_vec2i	ft_put_ctrl_light(t_mlx_ptrs *mlx_ptrs, t_putinfo put, uint32_t active);
t_vec2i	ft_put_ctrl_cam(t_mlx_ptrs *mlx_ptrs, t_putinfo put);

// menu_draw.c
uint32_t	fast_alpha_blend(uint32_t bg_color, t_menu menu);
void	ft_blend_background(t_img *img, t_img *veil, t_menu menu);

#endif
