/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output_ppm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:57:46 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/15 11:27:02 by gwolf            ###   ########.fr       */
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

static void	ft_write_to_file(int fd, int *pix_arr, int pixel_sum)
{
	int	i;

	i = 0;
	while (i < pixel_sum)
	{
		ft_write_pixel(pix_arr[i++], fd);
		if (i % 100 == 0)
			printf("\r%d%%", (i * 100) / pixel_sum);
	}
	printf("\r100%%\nFinished printing\n");
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

t_err	ft_output_as_ppm(const t_img img)
{
	int		fd;
	char	outfile[14];

	ft_create_filename(outfile);
	fd = 0;
	if (ft_err_open(outfile, O_CREAT | O_WRONLY | O_TRUNC, &fd))
		return (ERROR);
	ft_write_ppm_header(img.size.x, img.size.y, fd);
	printf("Printing scene to %s...\n", outfile);
	ft_write_to_file(fd, (int *)img.addr, img.size.x * img.size.y);
	if (ft_err_close(fd))
		return (ERROR);
	return (SUCCESS);
}

bool	ft_is_printing(t_render *render)
{
	bool	ret;

	pthread_mutex_lock(&render->mut_print);
	ret = render->is_printing;
	pthread_mutex_unlock(&render->mut_print);
	return (ret);
}

void	ft_toggle_is_printing(t_render *render)
{
	pthread_mutex_lock(&render->mut_print);
	render->is_printing = !render->is_printing;
	pthread_mutex_unlock(&render->mut_print);
}

void	*ft_output_threaded(void *arg)
{
	t_render		*render;

	render = ((t_thread_data *)arg)->arg;
	ft_output_as_ppm(render->mlx_ptrs.img);
	ft_toggle_is_printing(render);
	return (NULL);
}
