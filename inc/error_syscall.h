/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syscall.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:50:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/14 07:58:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_SYSCALL_H
# define ERROR_SYSCALL_H

/* ====== LIBRARIES ====== */

# include <fcntl.h>

# include "error_msg.h"

/* ====== FUNCTIONS ====== */

t_err	ft_err_open(const char *path, int flag, int *fd);
t_err	ft_err_close(int fd);
t_err	ft_err_malloc(void **ptr, size_t size);
t_err	ft_err_read(int fd, void *buf, size_t size, ssize_t *rd_bytes);

#endif