/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:57:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/10 19:25:01 by hmontoya         ###   ########.fr       */
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

/**
 * @brief It retireves the value of time_last_meal for this philo. 
*/
void	set_philo_state(t_philo *this, t_philo_state state)
{
	pthread_mutex_lock(&this->mt_state);
	this->state = state;
	pthread_mutex_unlock(&this->mt_state);
}
