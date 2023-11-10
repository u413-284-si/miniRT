/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:36:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/10 14:38:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <stddef.h>
# include "miniRT_error.h"

# define BUF_SIZE 300

/**
 * @brief Buffer structure.
 *
 * Simple implementation of a buffer.
 * @param str		Buffer string.
 * @param size		Size of malloced buffer memory in Bytes.
 * @param cur_pos	Current position inside malloced buffer
 * 					memory.
 */
typedef struct s_buf
{
	char	*str;
	size_t	size;
	size_t	cur_pos;
}	t_buf;

t_err	ft_buf_init(t_buf *buf);
void	ft_buf_clear(t_buf *buf);
t_err	ft_buf_double(t_buf *buf);
t_err	ft_buf_strlcpy(t_buf *buf, char *str, size_t len);
void	ft_buf_destroy(t_buf *buf);

#endif
