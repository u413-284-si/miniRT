/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:11:24 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/04 01:41:16 by sqiu             ###   ########.fr       */
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
