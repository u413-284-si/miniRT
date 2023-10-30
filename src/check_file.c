/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/30 14:46:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_filename(char *argv)
{
	int		len;
	char	*start;

	start = ft_strrchr(argv, '/');
	if (!start)
		start = argv;
	else
		start += 1;
	len = ft_strlen(start);
	if (!ft_strnstr(start + len - 3, ".rt", len))
	{
		ft_terminate("Wrong file extension", 0);
	}
}

void	ft_check_file(char *argv)
{
	int	fd;

	ft_check_filename(argv);
	fd = ft_err_open(argv, O_RDONLY, "Open() failed");
	ft_err_close(fd, "Close() failed");
}