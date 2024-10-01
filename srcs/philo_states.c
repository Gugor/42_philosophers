/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:12:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/01 17:45:30 by hmontoya         ###   ########.fr       */
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
    if (is_dead(philo))
    {
        print(philo, DIED);
        return (1);
    }
    print(philo, SLEEPING);
    philo->times_slept++;
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int eating(t_philo *philo)
{
	  if (check_dinner_state(philo) == 0)
		return (1);
    get_fork(philo, philo->leader_hand);
	  if (check_dinner_state(philo) == 0)
    {
      if (!philo->leader_hand)
        pthread_mutex_unlock(philo->left_hand);
      if (philo->leader_hand)
        pthread_mutex_unlock(philo->right_hand);
		  return (1);
    }
    get_fork(philo, !philo->leader_hand);
    print(philo, EATING);
    philo->time_last_meal = get_current_time('m');
    philo->state = EATING;
    philo_uwait(philo->time_to_eat * 1000L , philo); 
    put_fork(philo, philo->leader_hand);
    put_fork(philo, !philo->leader_hand);
    philo->times_eaten++;
    if (has_eaten_enough(philo))
    {
      print(philo, FULL);
      return (1);
    }
	return (0);	
}
