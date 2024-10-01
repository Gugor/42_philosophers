/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/01 18:12:39 by hmontoya         ###   ########.fr       */
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
	printf("Philo %i checking meals %i/%i\n", this->indx + 1, this->times_eaten, this->min_meals_to_eat);
	if (this->times_eaten >= this->min_meals_to_eat)
	{
		printf("FULL Philo %i checking meals %i/%i\n", this->indx + 1, this->times_eaten, this->min_meals_to_eat);
		this->state = STOPED;
		set_waiter_pfull(this->waiter);
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
	if (interval > this->time_to_die * 1000L)
	{
		set_dead_state(this->waiter, this->indx);
		this->time_of_death = get_current_time('m');
		set_waiter_state(this->waiter, ENDED);
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
		if (get_waiter_state(this->waiter) == PREPARING ||
		(this->state == STOPED && get_waiter_state(this->waiter) == DINNING))
			continue;
		if (this->state == STOPED)
		{
			printf("Settings meals %i\n", this->min_meals_to_eat);
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
