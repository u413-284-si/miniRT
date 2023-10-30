/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:23:15 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/30 14:36:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

/* ====== LIBRARIES ====== */

// Standard C libs
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

// Home-grown libs
#include "ft_fd.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

// error_terminate.c
void	ft_terminate(char *msg, int save_errno);

// error_syscall_wrapper.c
int		ft_err_open(const char *path, int flag, char *msg);
void	ft_err_close(int fd, char *msg);

#endif