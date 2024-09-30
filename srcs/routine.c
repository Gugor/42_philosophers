/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/30 18:16:38 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief I checks if the given philospher has eaten enough.
 * @param this `{t_philo}` a pointer to the given philo sturct. 
 * @returns `{int}`
 * `0` still not full
 * `1` has eaten enough
*/
int has_eaten_enough(t_philo *this)
{
	if (this->times_eaten == this->max_meals_to_eat)
	{
		set_waiter_state(this->waiter, ENDED);
		print(this, FULL);
		return (1);
	}
	return (0);	
}

/**
* @brief It finds wether the philosohpers has died or not, and set
* the waiter state to ENDED.
* @param this `{t_philo}` a pointer to the philo structure to check on.
* @returns `{int}`
*/
int is_dead(t_philo *this)
{
	int64_t interval;
	
	interval = get_elapsed_time(this->time_last_meal, 'm');
	if (interval > (this->time_to_die * 1000L))
	{
		set_dead_state(this->waiter);
		update_elapsed_time_to(&this->time_alive, this->birth, 'm');
		return (1);
	}
	return (0);
}


/**
 * @brief The routine for each philo.
*/
void *dinning(void *data)
{
	t_philo *this;

	this = (t_philo *)data;
	while (42)
	{
		if (this->state == STOPED)
		{
			this->time_last_meal = get_current_time('m');
			this->state = EATING;
		}
		if (check_dinner_state(this) == 0)
			return (NULL);
		eating(this);
		if (check_dinner_state(this) == 0)
			return (NULL);
		sleeping(this);
		if (check_dinner_state(this) == 0)
			return (NULL);
		thinking(this);
	}
	return (NULL) ;
}
