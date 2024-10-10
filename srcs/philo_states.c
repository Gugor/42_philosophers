/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/10 19:25:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Make a philo eat
*/
int	thinking(t_philo *philo)
{
	print(philo, THINKING);
	philo->state = THINKING;
	set_philo_state(philo, THINKING);
	philo->times_thought++;
	return (0);
}

/**
 * @brief Make a philo eat
*/
int	sleeping(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	philo_uwait(philo->time_to_sleep * 1000L);
	print(philo, SLEEPING);
	philo->times_slept++;
	return (0);
}

/**
 * @brief Make a philo eat
*/
int	eating(t_philo *philo)
{
	get_fork(philo, philo->leader_hand);
	get_fork(philo, !philo->leader_hand);
	set_philo_state(philo, EATING);
	set_philo_lstml(philo);
	philo_uwait(philo->time_to_eat * 1000L);
	print(philo, EATING);
	put_fork(philo, philo->leader_hand);
	put_fork(philo, !philo->leader_hand);
	philo->times_eaten++;
	if (has_eaten_enough(philo) > 0)
		return (1);
	return (0);
}
