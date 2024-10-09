/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:57:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/09 23:02:52 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It sets the value for time_last_meal to the 
 * given philosopher.
*/
void	set_philo_lstml(t_philo *this)
{
	pthread_mutex_lock(&this->mt_lstml);
	this->time_last_meal = get_current_time('m');
	pthread_mutex_unlock(&this->mt_lstml);
}