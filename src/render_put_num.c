/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:31:17 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/21 19:35:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_mlx_put_int(t_render *render, int pos[2], int num, int pad)
{
	int		numlen;
	char	str[8];

	if (num < 0)
		numlen = 1;
	else
		numlen = 0;
	numlen += ft_count_digit(num);
	if (numlen > 7)
	{
		mlx_string_put(render->mlx_ptr, render->win_ptr, pos[0], pos[1], 0x0, "max");
		return ;
	}
	ft_memset(str, 0, 8);
	pad -= numlen;
	if (pad > 0)
	{
		ft_itoa_in_place(num, str + pad);
		while (pad--)
			str[pad] = ' ';
	}
	else
		ft_itoa_in_place(num, str);
	mlx_string_put(render->mlx_ptr, render->win_ptr, pos[0], pos[1], 0x0, str);
}

void	ft_mlx_put_float(t_render *render, int pos[2], float num, int prec)
{
	int		numlen;
	char	str[8];
	int		padding;

	if (num < 0)
		numlen = 1;
	else
		numlen = 0;
	numlen += ft_count_digit(num);
	if (numlen > 3)
	{
		mlx_string_put(render->mlx_ptr, render->win_ptr, pos[0], pos[1], 0x0, "max");
		return ;
	}
	ft_memset(str, 0, 8);
	padding = 3 - numlen;
	ft_ftoa_in_place(num, str + padding, prec);
	while (padding--)
		str[padding] = ' ';
	mlx_string_put(render->mlx_ptr, render->win_ptr, pos[0], pos[1], 0x0, str);
}
