/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/14 19:28:42 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Make a philo eat
*/
int	thinking(t_philo *philo)
{
	print(philo, THINKING);
	philo->times_thought++;
	return (0);
}

/**
 * @brief Make a philo eat
*/
int	sleeping(t_philo *philo)
{
	philo_uwait(philo->time_to_sleep);
	print(philo, SLEEPING);
	philo->times_slept++;
	return (0);
}

/**
 * @brief Make a philo eat
*/
int	eating(t_philo *philo)
{
	if (philo->indx % 2 == 0)
		philo_uwait(2000);
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
