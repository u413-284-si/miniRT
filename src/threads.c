/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:28:01 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 11:19:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_threads.h"

t_err	ft_create_threads(void *arg, void *(*routine)(void *),
			t_thread_data threads[NUM_THREADS])
{
	int	i;
	int	ret;

	i = -1;
	while (++i < NUM_THREADS)
	{
		threads[i].id = i;
		threads[i].arg = arg;
		ret = pthread_create(&threads[i].t_id, NULL, routine, &threads[i]);
		errno = ret;
		if (errno)
		{
			threads[i].id = -1;
			ft_perror("pthread_create() failed", errno);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

void	ft_join_threads(t_thread_data threads[NUM_THREADS], bool join_all)
{
	int	i;

	i = -1;
	if (join_all)
	{
		while (++i < NUM_THREADS)
		{
			errno = pthread_join(threads[i].t_id, NULL);
			if (errno)
				ft_perror("pthread_join() failed", errno);
		}
		return ;
	}
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
		ft_join_threads(threads, false);
		return (ERROR);
	}
	ft_join_threads(threads, true);
	return (SUCCESS);
}
