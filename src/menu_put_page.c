/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:16:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 14:20:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"

void	ft_put_gae_scene(t_mlx_ptrs *mlx_ptrs, t_vec2i pos, uint32_t col, t_hittable active)
{
	ft_put_hittable(mlx_ptrs, pos, col, active);
}