/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/27 18:59:24 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Make a philo eat
*/
int thinking(t_philo *philo)
{
	if (check_dead_state(philo) == 0)
		return (1);
    print(philo, THINKING);
	usleep(10);
    if (is_dead(philo))
        return (1);
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int sleeping(t_philo *philo)
{
	if (check_dead_state(philo) == 0)
		return (1);
    print(philo, SLEEPING);
	usleep(philo->time_to_sleep);
    if (is_dead(philo))
        return (1);
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int eating(t_philo *philo)
{
	if (check_dead_state(philo) == 0)
		return (1);
    philo->time_last_meal = get_current_time('m');
    get_fork(philo, philo->leader_hand);
    get_fork(philo, !philo->leader_hand);
    print(philo, EATING);
    put_fork(philo, philo->leader_hand);
    put_fork(philo, !philo->leader_hand);
	usleep(philo->time_to_eat);
    if (is_dead(philo))
        return (1);
	return (0);	
}