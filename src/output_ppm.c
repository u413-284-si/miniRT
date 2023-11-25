/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ppm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:50:12 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/22 12:07:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "error_syscall.h"

void	ft_write_pixel(int col, int fd)
{
	t_colour	colour;

	colour = ft_convert_int2colour(col);
	ft_putnbr_fd(colour.r, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(colour.g, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(colour.b, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_write_ppm_header(int width, int height, int fd)
{
	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(height, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
}

t_err	ft_output_as_ppm(int *img_arr, int width, int height)
{
	int	fd;
	int	pixel_sum;
	int	i;

	fd = 0;
	if (ft_err_open("outfile.ppm", O_CREAT | O_WRONLY | O_TRUNC, &fd))
		return (ERROR);
	ft_write_ppm_header(width, height, fd);
	pixel_sum = width * height;
	i = 0;
	while (i < pixel_sum)
		ft_write_pixel(img_arr[i++], fd);
	if (ft_err_close(fd))
		return (ERROR);
	return (SUCCESS);
}
