/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output_ppm_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:57:46 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/21 13:46:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

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

static void	ft_create_filename(char outfile[14])
{
	static int	i;
	char		num[3];

	if (i++ > 99)
		i = 0;
	ft_strlcpy(outfile, "outfile_", 8);
	ft_itoa_in_place(i, num);
	ft_strlcat(outfile, num, 14);
	ft_strlcat(outfile, ".ppm", 14);
}

static void	ft_write_to_buffer(const t_img img, char *file_buffer)
{
	int			i;
	uint32_t	*pixel;

	pixel = (uint32_t *)img.addr;
	i = -1;
	while (i < img.size.x * img.size.y)
	{
		file_buffer[i * 3] = (*pixel & 0x00FF0000) >> 16;
		file_buffer[i * 3 + 1] = (*pixel & 0x0000FF00) >> 8;
		file_buffer[i * 3 + 2] = (*pixel & 0x000000FF);
		pixel += 1;
		i++;
	}
}

t_err	ft_output_as_ppm(const t_img img)
{
	int		fd;
	char	outfile[14];
	char	*file_buffer;

	ft_create_filename(outfile);
	fd = 0;
	if (ft_err_open(outfile, O_CREAT | O_WRONLY | O_TRUNC, &fd))
		return (ERROR);
	file_buffer = NULL;
	if (ft_err_malloc((void **)&file_buffer, img.size.x * img.size.y * 3))
	{
		ft_err_close(fd);
		return (ERROR);
	}
	ft_write_ppm_header(img.size.x, img.size.y, fd);
	ft_write_to_buffer(img, file_buffer);
	ft_putstr_fd(file_buffer, fd);
	free(file_buffer);
	if (ft_err_close(fd))
		return (ERROR);
	return (SUCCESS);
}
