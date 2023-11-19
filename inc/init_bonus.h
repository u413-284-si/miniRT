/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:05:27 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/19 22:36:16 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

/* ====== LIBRARIES ====== */

# include "entities_bonus.h"

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
