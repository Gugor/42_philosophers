/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/15 11:57:54 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Make a philo think
*/
int	thinking(t_philo *philo)
{
	print(philo, THINKING);
	return (0);
}

/**
 * @brief Make a philo sleep
*/
int	sleeping(t_philo *philo)
{
	philo_uwait(philo->time_to_sleep);
	print(philo, SLEEPING);
	return (0);
}

/**
 * @brief Make a philo eat
*/
int	eating(t_philo *philo)
{
	if (philo->indx % 2 == 0)
		philo_uwait(4000);
	get_forks(philo);
	set_philo_lstml(philo);
	philo_uwait(philo->time_to_eat);
	print(philo, EATING);
	put_forks(philo);
	philo->times_eaten++;
	if (has_eaten_enough(philo) > 0)
		return (1);
	return (0);
}
