/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:53:31 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/01 15:16:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "ft_fd.h"
# include "error_msg.h"

typedef float	t_mat4[4][4];

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;


void	ft_mat4_copy(const t_mat4 src, t_mat4 dst);
void	ft_mat4_set_identity(t_mat4 mat);

int		ft_inverse_matrix(const t_mat4 mat, t_mat4 inv);

void	ft_mat4_cam_look_at(t_mat4 mat, t_vec3 cam_pos, t_vec3 cam_dir, t_vec3 v_up);
void	ft_mat4_perspective(t_mat4 mat, float angle, float ratio, float near, float far);

t_vec4	ft_mult_vec4_mat4(t_vec4 vec, t_mat4 mat);
t_vec4	ft_vec4_create(float x, float y, float z, float w);
t_vec3	ft_vec3_create(float x, float y, float z);

#endif
