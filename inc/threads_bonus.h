/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:34:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/26 18:17:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_BONUS_H
# define THREADS_BONUS_H

/* ====== LIBRARIES ====== */

# include <pthread.h>

# include "miniRT_error.h"
# include "miniRT_config_bonus.h"

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
 * This way, ft_join_threads() can break out of the loop.
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
 * Joins created threads. If thread creation fail the last threads ID is set
 * to -1, which breaks out of the loop.
 * the threads which have been created.
 * @param threads	Array of t_thread_data.
 */
void	ft_join_threads(t_thread_data threads[NUM_THREADS]);

/**
 * @brief Creates a single thread, which is detached.
 *
 * If thread_create() fails, sets errno, ft_perror()s the error message and
 * returns ERROR.
 * If thread_create() succeeds detaches the thread.
 * @param arg		Argument to pass to routine
 * @param routine	Function to call
 * @return t_err	ERROR, if thread_create() fails or SUCCESS
 */
t_err	ft_spin_detached_thread(void *arg, void *(*routine)(void *));

#endif
