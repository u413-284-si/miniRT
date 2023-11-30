/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:53:31 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/30 08:50:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "ft_fd.h"
# include "error_msg.h"

typedef float	t_mat4[4][4];

void	ft_mat4_copy(const t_mat4 src, t_mat4 dst);
void	ft_mat4_set_identity(t_mat4 mat);

int		ft_inverse_matrix(const t_mat4 mat, t_mat4 inv);

#endif