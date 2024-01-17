/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:16:27 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/17 13:22:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_print_cam(const t_cam cam)
{
	printf("Camera:\n");
	printf("Position: ");
	ft_print_vec3(cam.centre);
	printf("Direction: ");
	ft_print_vec3(cam.direction);
	printf("FOV: %f\n", ft_radian_to_degree(cam.hfov));
	printf("\n");
}

void	ft_print_hittable(const t_hittable hittable)
{
	printf("ID: %d\n", hittable.id);
	if (hittable.type == SPHERE)
		ft_print_sphere(hittable.params.sp);
	else if (hittable.type == PLANE)
		ft_print_plane(hittable.params.pl);
	else if (hittable.type == CYLINDER)
		ft_print_cylinder(hittable.params.cy);
	printf("\n");
}

void	ft_print_sphere(const t_sphere sp)
{
	printf("Sphere:\n");
	printf("Centre: ");
	ft_print_vec3(sp.centre);
	printf("Radius: %f\n", sp.r);
	printf("Colour: ");
	ft_print_colour(sp.colour);
}

void	ft_print_plane(const t_plane pl)
{
	printf("Plane:\n");
	printf("Point: ");
	ft_print_vec3(pl.point);
	printf("Normal: ");
	ft_print_vec3(pl.normal);
	printf("Colour: ");
	ft_print_colour(pl.colour);
}

void	ft_print_cylinder(const t_cylinder cy)
{
	printf("Cylinder:\n");
	printf("Centre: ");
	ft_print_vec3(cy.centre);
	printf("Axis: ");
	ft_print_vec3(cy.axis);
	printf("Diameter: %.6f\n", cy.d);
	printf("Height: %.6f\n", cy.h);
	printf("Colour: ");
	ft_print_colour(cy.colour);
}
