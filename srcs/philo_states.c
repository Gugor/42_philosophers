/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/29 22:48:12 by hmontoya         ###   ########.fr       */
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
    philo->state = THINKING;
    philo->times_thought++;
  //  printf("Thinking: is dead?\n");
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
    philo->state = SLEEPING;
   // philo_uwait(philo->time_to_sleep * 1000L, philo); 
	usleep(philo->time_to_sleep * 1000L);
    philo->time_to_sleep++;
    //printf("Sleeping: is dead?\n");
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
    get_fork(philo, philo->leader_hand);
    get_fork(philo, !philo->leader_hand);
    print(philo, EATING);
    put_fork(philo, philo->leader_hand);
    put_fork(philo, !philo->leader_hand);
    philo->state = EATING;
   // philo_uwait(philo->time_to_eat * 1000L , philo); 
	usleep(philo->time_to_eat * 1000L);
    philo->time_last_meal = get_current_time('m');
    philo->times_eaten++;
   // printf("Eating: is dead?\n");
    if (is_dead(philo))
        return (1);
	return (0);	
}