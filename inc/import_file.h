/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:30:12 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 11:18:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_FILE_H
# define IMPORT_FILE_H

/* ====== LIBRARIES ====== */

# include "error_syscall.h"
# include "cleanup.h"
# include "miniRT_config.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Simple implementation of a buffer.
 * @param str		Buffer string.
 * @param size		Size of malloced buffer memory in bytes.
 * @param cur_pos	Current position of buffer.
 */
typedef struct s_buf
{
	char	*str;
	size_t	size;
	size_t	cur_pos;
}	t_buf;

/* ====== FUNCTIONS ====== */

// import_file.c

/**
 * @brief Check file extension, import file and prepare for use.
 *
 * Check extension with ft_isvalid_filename().
 * Open the file and import content with ft_read_and_split().
 * A NULL-terminated array is created.
 * Close the file. If error free imported line array.
 * @param filename Filename passed as argv[1].
 * @param lines Array where to save imported lines.
 * @return t_err ERROR if any subfunction fails.
 */
t_err		ft_import_file(char *filename, char ***lines);

/**
 * @brief Check if valid file extension.
 *
 * Checks if the last three characters are ".rt".
 * If not prints error.
 * @param filename Filename passed as argv[1].
 * @return true Filename has ".rt" as last three chars.
 * @return false Filename is not valid.
 */
bool		ft_isvalid_filename(char *filename);

/**
 * @brief Import file and split it into lines.
 *
 * Initialize buffer with ft_buf_init().
 * Read the whole file into buffer with ft_buf_read_file().
 * Convert file into array of lines with ft_split().
 * Split char is newline '\n', which gets rid superfluous newlines.
 * Destroy the buffer with ft_buf_destroy().
 * If error is enountered buffer also gets destroyed.
 * @param fd File descriptor of opened file.
 * @param lines Array where to store lines.
 * @return t_err ERROR if any subfunction fails.
 */
t_err		ft_read_and_split(int fd, char ***lines);

// import_file_buffer.c

/**
 * @brief Initiates a t_buf buffer
 *
 * @param buf Pointer to buffer
 * @return t_err ERROR if malloc() fails.
 */
t_err		ft_buf_init(t_buf *buf);

/**
 * @brief Destroy malloced buffer.
 *
 * @param buf Pointer to buffer.
 */
void		ft_buf_destroy(t_buf *buf);

/**
 * @brief Set buffer to zero.
 *
 * @param buf Pointer to buffer.
 */
void		ft_buf_clear(t_buf *buf);

/**
 * @brief Doubles buffer size and copies content into new malloc'd buffer
 *
 * @param buf Pointer to buffer.
 * @return t_err ERROR if malloc() fails.
 */
t_err		ft_buf_double(t_buf *buf);

/**
 * @brief Reads provided file into buffer.
 *
 * In a loop:
 * - Read for remaining buffer size.
 * - If buffer is full double size with ft_buf_double().
 * - If whole file is read break.
 * Buffer gets zero terminated.
 * @param buf Pointer to buffer.
 * @param fd File descriptor of opened file.
 * @return t_err ERROR if read() or ft_buf_double() fails.
 */
t_err		ft_buf_read_file(t_buf *buf, int fd);

#endif