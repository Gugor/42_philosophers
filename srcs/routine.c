/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/29 22:49:32 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_dead(t_philo *this)
{
	int64_t interval;
	
	interval = get_elapsed_time(this->time_last_meal, 'm');
	//printf("	Interval %ld philo %i\n", interval, this->indx);
	if (interval > (this->time_to_die * 1000L))
	{
		update_elapsed_time_to(&this->time_alive, this->birth, 'm');
		//printf("		Is dead philo %i (%ld)\n", this->indx, this->time_alive);
		set_dead_state(this->waiter);
		print(this, DIED);
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
	while (check_dead_state(this) == 1)
	{
		if (this->state == STOPED)
		{
			this->time_last_meal = get_current_time('m');
			this->state = EATING;
		}
		if (eating(this))
			break;
		if (sleeping(this))
			break ;
		if (thinking(this))
			break ;
	}
	return (NULL) ;
}
