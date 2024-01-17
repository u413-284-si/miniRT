/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity_sp_pl_cy_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:34:38 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/17 13:23:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	ft_parse_sphere(char *line, t_hittable *sphere, size_t id)
{
	t_sphere	*params;

	sphere->id = id + 1;
	sphere->type = SPHERE;
	params = &sphere->params.sp;
	ft_parse_float_block(&line, &params->centre);
	ft_parse_float(&line, &params->r);
	params->r = params->r / 2.0;
	ft_parse_float(&line, &sphere->shininess);
	ft_parse_float(&line, &sphere->reflectivity);
	ft_parse_float(&line, &sphere->checkered);
	ft_parse_colour_block(&line, &params->colour);
}

void	ft_parse_plane(char *line, t_hittable *plane, size_t id)
{
	t_plane	*params;

	plane->id = id + 1;
	plane->type = PLANE;
	params = &plane->params.pl;
	ft_parse_float_block(&line, &params->point);
	ft_parse_float_block(&line, &params->normal);
	params->normal = ft_vec3_norm(params->normal);
	ft_parse_float(&line, &plane->shininess);
	ft_parse_float(&line, &plane->reflectivity);
	ft_parse_float(&line, &plane->checkered);
	ft_parse_colour_block(&line, &params->colour);
}

void	ft_parse_cylinder(char *line, t_hittable *cylinder, size_t id)
{
	t_cylinder	*params;

	cylinder->id = id + 1;
	cylinder->type = CYLINDER;
	params = &cylinder->params.cy;
	ft_parse_float_block(&line, &params->centre);
	ft_parse_float_block(&line, &params->axis);
	params->axis = ft_vec3_norm(params->axis);
	ft_parse_float(&line, &params->d);
	ft_parse_float(&line, &params->h);
	ft_parse_float(&line, &cylinder->shininess);
	ft_parse_float(&line, &cylinder->reflectivity);
	ft_parse_float(&line, &cylinder->checkered);
	ft_parse_colour_block(&line, &params->colour);
	ft_cy_calc_caps(params);
}

void	ft_parse_cone(char *line, t_hittable *cone, size_t id)
{
	t_cone	*params;

	cone->id = id;
	cone->type = CONE;
	params = &cone->params.co;
	ft_parse_float_block(&line, &params->apex);
	ft_parse_float_block(&line, &params->axis);
	params->axis = ft_vec3_norm(params->axis);
	ft_parse_float(&line, &params->r);
	ft_parse_float(&line, &params->h);
	ft_parse_float(&line, &cone->shininess);
	ft_parse_float(&line, &cone->reflectivity);
	ft_parse_float(&line, &cone->checkered);
	ft_parse_colour_block(&line, &params->colour);
	params->angle = atan(params->r / params->h) + EPSILON;
	params->base = ft_vec3_add(params->apex, \
		ft_vec3_scale(params->axis, params->h));
}
