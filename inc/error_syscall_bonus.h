/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syscall_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:50:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 11:46:05 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_SYSCALL_BONUS_H
# define ERROR_SYSCALL_BONUS_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <fcntl.h>

// Home-grown libs
# include "error_type_bonus.h"
# include "error_msg_bonus.h"

/* ====== FUNCTIONS ====== */

/**
 * @brief Wrapper function for open() to print errno.
 *
 * @param path		Path string to file to open.
 * @param flag		Flags given to open().
 * @param fd		File descriptor to assign to opened file.
 * @return t_err	SUCCESS, ERROR
 */
t_err	ft_err_open(const char *path, int flag, int *fd);

/**
 * @brief Wrapper function for close() to print errno.
 *
 * @param fd		File descriptor of file to be closed.
 * @return t_err 	SUCCESS, ERROR
 */
t_err	ft_err_close(int fd);

/**
 * @brief Wrapper function for malloc() to print errno.
 *
 * @param ptr		Pointer where to save the malloced memory.
 * @param size		Size of the memory block.
 * @return t_err	SUCCESS, ERROR
 */
t_err	ft_err_malloc(void **ptr, size_t size);

/**
 * @brief Wrapper function for read() to print errno.
 *
 * @param fd 		File descriptor to read.
 * @param buf 		File buffer, where to store.
 * @param size 		Size of the read block.
 * @param rd_bytes	Pointer to save return value of read().
 * @return t_err SUCESS, ERROR
 */
t_err	ft_err_read(int fd, void *buf, size_t size, ssize_t *rd_bytes);

#endif