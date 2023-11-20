/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:50:12 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 23:12:07 by gwolf            ###   ########.fr       */
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

t_err	ft_print_image_as_ppm(t_image image, t_buffer buffer)
{
	int	fd;
	int	pixel_sum;
	int	*arr;
	int	i;

	fd = 0;
	ft_err_open("outfile.ppm", O_CREAT | O_WRONLY | O_TRUNC, &fd);
	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(image.image_width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(image.image_height, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
	pixel_sum = image.image_height * image.image_width;
	arr = (int *)buffer.addr;
	i = 0;
	while (i < pixel_sum)
		ft_write_pixel(arr[i++], fd);
	ft_err_close(fd);
	return (SUCCESS);
}
