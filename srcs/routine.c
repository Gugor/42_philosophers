/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/27 18:24:49 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_dead(t_philo *this)
{
	int64_t interval;
	
	interval = get_elapsed_time(this->time_last_meal, 'm');
	if (interval > (this->time_to_die * 1000L))
	{
		set_dead_state(this->waiter);
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
		update_elapsed_time_to(&this->time_alive, this->birth, 'm');
		if (eating(this))
			break;
		if (sleeping(this))
			break ;
		if (thinking(this))
			break ;
		if (is_dead(this))
			return (NULL);
	}
	return (NULL) ;
}