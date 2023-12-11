/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:53:31 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/11 16:50:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# include "ft_fd.h"
# include "error_msg.h"
# include "vec4.h"

/* ====== TYPEDEFS ====== */

typedef struct s_mat4
{
	float	mat[4][4];
}	t_mat4;

/* ====== FUNCTIONS ====== */

t_mat4	ft_mat4_set_identity(void);
t_mat4	ft_mat4_copy(const t_mat4 src);
t_vec4	ft_mat4_mult_vec4(const t_mat4 mat, const t_vec4 vec);
void	ft_mat4_print(t_mat4 mat);

t_mat4	ft_mat4_inverse(t_mat4 mat);

t_mat4	ft_mat4_cam_look_at(t_vec3 cam_pos, t_vec3 cam_dir, t_vec3 v_up);
t_mat4	ft_mat4_perspective(float angle, float ratio, float near, float far);

#endif
