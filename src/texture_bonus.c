/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:11:24 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/05 01:51:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "texture_bonus.h"

void	ft_apply_checker_texture(t_hitrecord *rec)
{
	if ((int)(floor(rec->u) + floor(rec->v)) % 2)
		rec->colour = (t_colour){0.2, 0.2, 0.2};
	else
		rec->colour = (t_colour){1.0, 1.0, 1.0};
}

float	ft_set_tiling(const float uv, const float scale)
{
	float		out;

	out = uv;
	if (fabs(out) > 1)
		out = fmod(out, scale) / scale;
	else
	{
		if (scale < 1)
			out = fmod(out / scale, 1);
		else
			out /= scale;
	}
	if (out < 0)
		out = 1 - fabs(out);
	return (out);
}
