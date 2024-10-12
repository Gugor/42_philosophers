/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:56:12 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/12 19:43:44 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It retireves the value of time_last_meal for this philo. 
*/
int64_t	get_philo_lstml(t_philo *this)
{
	int64_t	time;

	pthread_mutex_lock(&this->mt_lstml);
	time = this->time_last_meal;
	pthread_mutex_unlock(&this->mt_lstml);
	return (time);
}

/**
 * @brief It retireves the value of time_last_meal for this philo. 
*/
int64_t	get_philo_tod(t_philo *this)
{
	int64_t	time;

	pthread_mutex_lock(&this->mt_tod);
	time = this->time_of_death;
	pthread_mutex_unlock(&this->mt_tod);
	return (time);
}

/**
 * @brief It retireves the value of time_last_meal for this philo. 
*/
int64_t	get_philo_ttd(t_philo *this)
{
	int64_t	time;

	pthread_mutex_lock(&this->mt_ttd);
	time = this->time_to_die;
	pthread_mutex_unlock(&this->mt_ttd);
	return (time);
}

/**
 * @brief It retireves the value of time_last_meal for this philo. 
*/
int64_t	get_philo_state(t_philo *this)
{
	t_philo_state	state;

	pthread_mutex_lock(&this->mt_state);
	state = this->state;
	pthread_mutex_unlock(&this->mt_state);
	return (state);
}
