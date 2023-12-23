/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:23:15 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 11:46:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_TYPE_H
# define ERROR_TYPE_H

/* ====== TYPEDEFS ====== */

/**
 * @brief Gives return of function explicit meaning with SUCCESS or ERROR.
 *
 */
typedef enum e_err {
	SUCCESS,
	ERROR
}	t_err;

#endif