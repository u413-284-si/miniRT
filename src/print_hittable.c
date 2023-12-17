/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:16:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/17 10:48:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_print_vec3(const t_vec3 vec)
{
	printf("x: %f, y: %f, z: %f\n", vec.x, vec.y, vec.z);
}

void	ft_print_colour(const t_colour col)
{
	printf("r: %f, g: %f, b: %f\n", col.r, col.g, col.b);
}

void	ft_print_sphere(const t_sphere sp)
{
	printf("Sphere:\n");
	printf("Centre: ");
	ft_print_vec3(sp.centre);
	printf("Radius: %f\n", sp.r);
	printf("Colour: ");
	ft_print_vec3(sp.colour);
}

void	ft_print_plane(const t_plane pl)
{
	printf("Plane:\n");
	printf("Point: ");
	ft_print_vec3(pl.point);
	printf("Normal: ");
	ft_print_vec3(pl.normal);
	printf("Colour: ");
	ft_print_vec3(pl.colour);
}
