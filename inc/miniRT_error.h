/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:23:15 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/13 14:31:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

// Home-grown libs
# include "ft_fd.h"

/* ====== TYPEDEFS ====== */

typedef enum e_err {
	SUCCESS,
	ERROR
}	t_err;

/* ====== FUNCTIONS ====== */

// error_terminate.c
void	ft_terminate(void);
void	ft_perror(char *msg, int save_errno);

// error_syscall_wrapper.c
t_err	ft_err_open(const char *path, int flag, int *fd);
t_err	ft_err_close(int fd);
t_err	ft_err_malloc(void **ptr, size_t size);
t_err	ft_err_read(int fd, void *buf, size_t size, ssize_t *rd_bytes);

#endif