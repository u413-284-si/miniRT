/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:32:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/03 12:36:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

bool	ft_hit_scene(t_entities scene, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	return (ft_hit_scene_sp(scene, ray, rec, ray_d));
}
