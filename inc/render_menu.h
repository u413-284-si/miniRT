/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:57:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 17:15:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MENU_H
# define RENDER_MENU_H

/* ====== LIBRARIES ====== */

# include "render.h"
# include "vec2.h"

/* ====== MACROS ====== */

# define NUMLEN 10

/* ====== TYPEDEFS ====== */

typedef struct s_numinfo
{
	union
	{
		int		numi;
		float	numf;
	};
	int		pad;
	int		prec;
}	t_numinfo;

// menu_put_num.c

void	ft_mlx_put_int(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_numinfo numinfo);
void	ft_mlx_put_float(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_numinfo numinfo);

// menu_put_element.c

void	ft_put_3d_point(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_vec3 point, char *name);
void	ft_put_unit_vec(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_vec3 vec, char *name);
void	ft_put_colour(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_colour colour);

// menu_put_hittable.c

void	ft_put_hittable(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_hittable hittable);
void	ft_put_sphere(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_sphere sp);
void	ft_put_plane(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_plane pl);
void	ft_put_cylinder(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_cylinder cy);

// menu_put_camera_lights.c

void	ft_put_camera(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_cam cam);
void	ft_put_light(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, t_light light);

#endif