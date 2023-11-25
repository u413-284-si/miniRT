/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_put_num_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:30:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/21 19:38:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_count_digit(int num)
{
	int	i;

	if (num == 0)
		i = 1;
	else
		i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_str_rev(char *str)
{
	int		len;
	int		i;
	int		end;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	end = len - 1;
	while (i < end)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		i++;
		end--;
	}
}

void	ft_ftoa_in_place(float num, char *str, int precision)
{
	int		integer_part;
	float	fractional_part;
	int		i;

	integer_part = (int)num;
	fractional_part = num - integer_part;
	if (fractional_part < 0 && integer_part == 0)
	{
		str[0] = '-';
		str[1] = '0';
		i = 2;
	}
	else
		i = ft_itoa_in_place(integer_part, str);
	if (fractional_part < 0)
		fractional_part = -fractional_part;
	str[i++] = '.';
	while (precision-- > 0)
	{
		fractional_part *= 10;
		integer_part = (int)fractional_part;
		str[i++] = integer_part + '0';
		fractional_part -= integer_part;
	}
	str[i] = '\0';
}

int	ft_itoa_in_place(int num, char *str)
{
	int	i;
	int	is_negative;

	i = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	else
		is_negative = 0;
	str[i++] = num % 10 + '0';
	num /= 10;
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	if (is_negative)
		str[i++] = '-';
	ft_str_rev(str);
	str[i] = '\0';
	return (i);
}
