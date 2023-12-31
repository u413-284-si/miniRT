/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:05:27 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/17 15:08:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

/* ====== LIBRARIES ====== */

# include "entities.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

/**
 * @brief Builds the scene by filling it with entities
 * 
 * @param scene 	Struct with all entities
 */
void		ft_create_scene(t_entities *scene);

/**
 * @brief Initiates all the lights in the scene
 * 
 * @param scene 	Struct with all entities
 */
void		ft_initiate_lights(t_entities *scene);

/**
 * @brief Initiates all spheres in the scene
 * 
 * @param obj 		Array of all hittables
 */
void		ft_initiate_spheres(t_hittable *obj);

/**
 * @brief Initiates all planes in the scene
 * 
 * @param obj 		Array of all hittables
 */
void		ft_initiate_planes(t_hittable *obj);

/**
 * @brief Initiates all cylinders in the scene
 * 
 * @param obj 		Array of all hittables
 */
void		ft_initiate_cylinders(t_hittable *obj);

#endif
