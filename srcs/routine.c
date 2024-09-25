/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/25 21:18:17 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_dead(t_philo *this)
{
	if ((update_elapsed_time_to(&this->time_alive, this->time_last_meal, 'm') / 1000L) > (this->time_to_die))
	{
		printf("Philo as died! ☠️\n");
		this->state = DIED;
		return(1);
	}
	
}

/**
 * @brief Make a philo eat
*/
int think(t_philo *philo)
{
	
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int sleep(t_philo *philo)
{
	return (0);	
}

/**
 * @brief Make a philo eat
*/
int eat(t_philo *philo)
{
		
	return (0);	
}

/**
 * @brief The routine for each philo.
*/
void *dinning(void *data)
{
	t_philo *this;

	this = (t_philo *)data;
	printf("Dinner state: %u\n", this->state);
	while(this->waiter->state != ENDED)
	{
		printf("1 - Time alive %i => %ld | Time to  die: %i\n", this->indx, this->time_alive / 1000L, this->time_to_die);
		printf("2 - Time alive %i => %ld\n", this->indx, this->time_alive / 1000L);
		/*if (dinner->state == PREPARING)
			printf("Preparing dinner\n");
		else
		{*/
//			update_elapsed_time_to();
			//printf("Dinning...(Time:%ld)\n", dinner->start_tm / 1000000L);
			//printf("Num of philos => %i \n", dinner->settings->num_of_philos);
		//}
	}
	return (NULL) ;
}