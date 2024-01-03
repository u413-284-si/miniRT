/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output_ppm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:57:46 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/03 17:21:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "error_syscall.h"

static void	ft_write_pixel(int col, int fd)
{
	ft_putnbr_fd(col >> 16 & 0xFF, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(col >> 8 & 0xFF, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(col & 0xFF, fd);
	ft_putchar_fd('\n', fd);
}

static void	ft_write_ppm_header(int width, int height, int fd)
{
	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(height, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
}

t_err	ft_output_as_ppm(const t_img img, bool *is_printing)
{
	int	fd;
	int	pixel_sum;
	int	i;
	int	*addr;

	if (*is_printing)
		return (SUCCESS);
	*is_printing = true;
	fd = 0;
	if (ft_err_open("outfile.ppm", O_CREAT | O_WRONLY | O_TRUNC, &fd))
		return (ERROR);
	ft_write_ppm_header(img.size.x, img.size.y, fd);
	pixel_sum = img.size.x * img.size.y;
	i = 0;
	addr = (int *)img.addr;
	while (i < pixel_sum)
		ft_write_pixel(addr[i++], fd);
	if (ft_err_close(fd))
		return (ERROR);
	*is_printing = false;
	return (SUCCESS);
}
