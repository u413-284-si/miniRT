/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/30 16:41:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "ft_lst.h"

bool	ft_check_filename(char *argv)
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
		return (true);
	}
	return (false);
}

void	ft_check_file(char *argv)
{
	int	fd;

	if (ft_check_filename(argv))
		ft_terminate("Wrong file extension", 0);
	fd = 0;
	if (ft_err_open(argv, O_RDONLY, &fd))
		ft_terminate("Open() failed", errno);
	if (ft_err_close(fd))
		ft_terminate("Close() failed", errno);
}

bool	ft_check_line(int fd)
{
	char	*tmp;
	t_list	*head;

	tmp = get_next_line(fd);
	head = NULL;
	if (tmp[0] == '\n' || tmp[0] == '\0')
		free(tmp);
	else
	{
		if (ft_is_valid_line(tmp))
			ft_lstadd_front(&head, ft_lstnew(tmp));
		else
			ft_lstclear(&head, free);
			return true;
	}
	// check_line - empty or identifier
	// pass line
	// identify line - validate - add to list
}

bool	ft_is_valid_line(char *tmp)
{
	if (ft_strncmp(tmp, "A ", 2))
		return (ft_check_ambient(tmp + 2));
	else if (ft_strncmp(tmp, "C ", 2))
		return (ft_check_camera(tmp + 2));
	else if (ft_strncmp(tmp, "L ", 2))
		return (ft_check_light(tmp + 2));
	else if (ft_strncmp(tmp, "sp ", 3))
		return (ft_check_sphere(tmp + 3));
	else if (ft_strncmp(tmp, "pl ", 3))
		return (ft_check_plane(tmp + 3));
	else if (ft_strncmp(tmp, "cy ", 3))
		return (ft_check_cylinder(tmp + 3));
	return (false);
}
