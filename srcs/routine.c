/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/26 12:49:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int is_dead(t_philo *this)
{
	int64_t interval;
	
	interval = get_elapsed_time(this->time_last_meal, 'm');
	printf("Last meal: %ld time elapsed: %ld\n", this->time_last_meal, interval);
	if (interval > (this->time_to_die * 1000L))
	{
		printf("Philo as died! %ld ☠️\n", interval / 1000L);
		this->state = DIED;
		exit(1);
	}
	
}

/**
 * @brief Make a philo eat
*/
static int think(t_philo *philo)
{
	
	return (0);	
}

/**
 * @brief Make a philo eat
*/
static int sleeping(t_philo *philo)
{
	if (philo->state == SLEEPING)
	{
		usleep(philo->time_to_sleep);
		return (1);
	}
	return (0);	
}

/**
 * @brief Make a philo eat
*/
static int eat(t_philo *philo)
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
	//printf("Dinner state: %u\n", this->state);
	while(this->waiter->state != ENDED)
	{
		//printf("Philo %i has leader hand: %i\n",this->indx, this->leader_hand);
		//printf("Philo %i has fork in left hand: %p\n",this->indx, this->left_hand);
		//printf("Philo %i has fork in right hand: %p\n",this->indx, this->right_hand);
		//eat(this);
		is_dead(this);
		//usleep(700000);	
	}
	return (NULL) ;
}