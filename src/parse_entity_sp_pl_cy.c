/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity_sp_pl_cy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:34:38 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/24 21:14:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_parse_sphere(char *line, t_hittable *sphere, size_t id)
{
	t_sphere	*params;

	sphere->id = id;
	sphere->type = SPHERE;
	params = &sphere->params.sp;
	ft_parse_float_block(&line, &params->centre);
	ft_parse_float(&line, &params->d);
	ft_parse_colour_block(&line, &params->colour);
}

void	ft_parse_plane(char *line, t_hittable *plane, size_t id)
{
	t_plane	*params;

	plane->id = id;
	plane->type = PLANE;
	params = &plane->params.pl;
	ft_parse_float_block(&line, &params->point);
	ft_parse_float_block(&line, &params->normal);
	ft_parse_colour_block(&line, &params->colour);
}

void	ft_parse_cylinder(char *line, t_hittable *cylinder, size_t id)
{
	t_cylinder	*params;

	cylinder->id = id;
	cylinder->type = CYLINDER;
	params = &cylinder->params.cy;
	ft_parse_float_block(&line, &params->centre);
	ft_parse_float_block(&line, &params->axis);
	params->axis = ft_vec3_norm(params->axis);
	ft_parse_float(&line, &params->d);
	ft_parse_float(&line, &params->h);
	ft_parse_colour_block(&line, &params->colour);
	params->cap1 = ft_vec3_add(params->centre, \
		ft_vec3_scale(params->axis, -params->h * 0.5));
	params->cap2 = ft_vec3_add(params->centre, \
		ft_vec3_scale(params->axis, params->h * 0.5));
}
