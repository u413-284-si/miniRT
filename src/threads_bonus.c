/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:28:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 17:10:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"

t_err	ft_create_threads(void *arg, void *(*routine)(void *),
			t_thread_data threads[NUM_THREADS])
{
	int	i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		threads[i].id = i;
		threads[i].arg = arg;
		errno = pthread_create(&threads[i].t_id, NULL, routine, &threads[i]);
		if (errno)
		{
			threads[i].id = -1;
			ft_perror("pthread_create() failed", errno);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

void	ft_join_threads(t_thread_data threads[NUM_THREADS])
{
	int	i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		if (threads[i].id == -1)
			break ;
		errno = pthread_join(threads[i].t_id, NULL);
		if (errno)
			ft_perror("pthread_join() failed", errno);
	}
}

t_err	ft_spin_threads(void *arg, void *(*routine)(void *))
{
	t_thread_data	threads[NUM_THREADS];

	if (ft_create_threads(arg, routine, threads))
	{
		ft_join_threads(threads);
		return (ERROR);
	}
	ft_join_threads(threads);
	return (SUCCESS);
}

t_err	ft_spin_detached_thread(void *arg, void *(*routine)(void *))
{
	static t_thread_data	thread;

	thread.id = 1;
	thread.arg = arg;
	errno = pthread_create(&thread.t_id, NULL, routine, &thread);
	if (errno)
	{
		ft_perror("pthread_create() failed", errno);
		return (ERROR);
	}
	errno = pthread_detach(thread.t_id);
	if (errno)
		ft_perror("pthread_detach() failed", errno);
	return (SUCCESS);
}
