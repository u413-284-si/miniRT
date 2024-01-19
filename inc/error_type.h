/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:23:15 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 18:28:12 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_TYPE_H
# define ERROR_TYPE_H

/* ====== TYPEDEFS ====== */

/**
 * @brief Gives return of function explicit meaning with SUCCESS or ERROR.
 *
 */
typedef enum e_err
{
	SUCCESS,
	ERROR
}	t_err;

#endif