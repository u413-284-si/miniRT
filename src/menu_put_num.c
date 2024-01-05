/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:30:56 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:27:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_mlx_put_str(t_mlx_ptrs *mlx_ptrs, t_putinfo put, char *str)
{
	mlx_string_put(mlx_ptrs->mlx_ptr, mlx_ptrs->win_ptr,
		put.pos.x, put.pos.y, put.col, str);
}

void	ft_mlx_put_int(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_numinfo numinfo)
{
	int		numlen;
	char	str[NUMLEN];

	numlen = ft_numlen(numinfo.numi);
	numinfo.pad -= numlen;
	if (numinfo.pad + numlen > NUMLEN - 1)
	{
		ft_mlx_put_str(mlx_ptrs, put, "max");
		return ;
	}
	ft_memset(str, 0, NUMLEN);
	if (numinfo.pad > 0)
	{
		ft_itoa_in_place(numinfo.numi, str + numinfo.pad);
		while (numinfo.pad--)
			str[numinfo.pad] = ' ';
	}
	else
		ft_itoa_in_place(numinfo.numi, str);
	ft_mlx_put_str(mlx_ptrs, put, str);
}

void	ft_mlx_put_float(t_mlx_ptrs *mlx_ptrs, t_putinfo put, t_numinfo numinfo)
{
	int		numlen;
	char	str[NUMLEN];

	numlen = ft_numlen(numinfo.numf);
	if (numlen == 1 && numinfo.numf < 0)
		numlen++;
	numinfo.pad -= numlen;
	if (numinfo.pad + numlen + 1 + numinfo.prec > NUMLEN - 1)
	{
		ft_mlx_put_str(mlx_ptrs, put, "max");
		return ;
	}
	ft_memset(str, 0, NUMLEN);
	if (numinfo.pad > 0)
	{
		ft_ftoa_in_place(numinfo.numf, str + numinfo.pad, numinfo.prec);
		while (numinfo.pad--)
			str[numinfo.pad] = ' ';
	}
	else
		ft_ftoa_in_place(numinfo.numf, str, numinfo.prec);
	ft_mlx_put_str(mlx_ptrs, put, str);
}
