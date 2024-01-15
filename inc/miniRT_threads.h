/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_threads.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:34:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/15 22:19:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_THREADS_H
# define MINIRT_THREADS_H

/* ====== LIBRARIES ====== */

# include <pthread.h>
# include "error_type.h"
# include "error_msg.h"

/* ====== MACROS ====== */

# define NUM_THREADS 16

/* ====== STRUCTS ====== */

typedef struct s_thread_data
{
	int32_t		id;
	pthread_t	t_id;
	void		*arg;
}	t_thread_data;

/* ====== FUNCTIONS ====== */

/**
 * @brief Creates NUM_THREADS threads and joins them.
 *
 * Routine can be any function which takes a void pointer as argument and
 * returns a void pointer.
 * @param arg		Argument to pass to routine
 * @param routine	Function to call
 * @return t_err	ERROR, if thread_create() fails or SUCCESS
 */
t_err	ft_spin_threads(void *arg, void *(*routine)(void *));

/**
 * @brief Creates NUM_THREADS threads and calls routine with arg.
 *
 * Catches return of thread_create() in errno. If it fails, ft_perror()s
 * the error message and sets current thread id to -1.
 * This way, ft_join_threads() can be called with join_all = false to join
 * only the threads which have been created. Then returns ERROR.
 * @param arg		Argument to pass to routine
 * @param routine	Function to call
 * @param threads	Array of t_thread_data
 * @return t_err	ERROR, if thread_create() fails or SUCCESS
 */
t_err	ft_create_threads(void *arg, void *(*routine)(void *),
			t_thread_data threads[NUM_THREADS]);

/**
 * @brief Joins threads.
 *
 * If join_all is true, joins all threads. If join_all is false, joins only
 * the threads which have been created.
 * @param threads	Array of t_thread_data
 * @param join_all	Whether to join all threads or only the ones which have
 * 					been created
 */
void	ft_join_threads(t_thread_data threads[NUM_THREADS], bool join_all);

/**
 * @brief Creates a single thread, which is detached.
 *
 * If thread_create() fails, sets errno, ft_perror()s the error message and
 * returns ERROR.
 * If thread_create() succeeds, detaches the thread and returns SUCCESS.
 * @param arg		Argument to pass to routine
 * @param routine	Function to call
 * @return t_err	ERROR, if thread_create() fails or SUCCESS
 */
t_err	ft_spin_detached_thread(void *arg, void *(*routine)(void *));

#endif
