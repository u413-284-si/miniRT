/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:16:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/20 11:31:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

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
	printf("Cap1: ");
	ft_print_vec3(cy.cap1);
	printf("Cap2: ");
	ft_print_vec3(cy.cap2);
	printf("Radius: %f\n", cy.d / 2.0);
	printf("Colour: ");
	ft_print_colour(cy.colour);
}
