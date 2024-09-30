/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/30 18:41:56 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Make a philo eat
*/
int thinking(t_philo *philo)
{
  if (check_dinner_state(philo) == 0)
    return (1);
  print(philo, THINKING);
  philo->state = THINKING;
  philo->times_thought++;
  if (is_dead(philo))
  {
    print(philo, DIED);
    return (1);
  }
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int sleeping(t_philo *philo)
{
	if (check_dinner_state(philo) == 0)
		return (1);
    philo->state = SLEEPING;
    philo_uwait(philo->time_to_sleep * 1000L, philo); 
    philo->times_slept++;
    if (is_dead(philo))
    {
        print(philo, DIED);
        return (1);
    }
    print(philo, SLEEPING);
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int eating(t_philo *philo)
{
	if (check_dinner_state(philo) == 0 || is_dead(philo))
		return (1);
    get_fork(philo, philo->leader_hand);
    get_fork(philo, !philo->leader_hand);
    philo->time_last_meal = get_current_time('m');
    philo->state = EATING;
    philo_uwait(philo->time_to_eat * 1000L , philo); 
    philo->times_eaten++;
    if (is_dead(philo) || has_eaten_enough(philo))
    {
        if (is_dead(philo))
          print(philo, DIED);
        if (has_eaten_enough(philo))
          print(philo, FULL);
        pthread_mutex_unlock(philo->left_hand);
        pthread_mutex_unlock(philo->right_hand);
        return (1);
    }
    print(philo, EATING);
    put_fork(philo, philo->leader_hand);
    put_fork(philo, !philo->leader_hand);
	return (0);	
}