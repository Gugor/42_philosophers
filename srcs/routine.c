/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/26 19:23:55 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int is_dead(t_philo *this)
{
	int64_t interval;
	
	interval = get_elapsed_time(this->time_last_meal, 'm');
	printf("Philo %i, last meal: %ld time elapsed: %ld\n",this->indx, this->time_last_meal, interval);
	printf("Philo %i, interval %ldmcs %ldms, time to die %ld\n", this->indx, interval, interval / 1000L, this->time_to_die);
	if (interval > (this->time_to_die * 1000L))
	{
		printf("Philo %i has died! %ld ☠️\n", this->indx, interval);
		this->state = DIED;
		pthread_mutex_lock(&this->waiter->mt_state);
		this->waiter->state = ENDED;
		pthread_mutex_unlock(&this->waiter->mt_state);
		pthread_mutex_lock(&this->waiter->mt_deads);
		this->waiter->deads += 1;
		pthread_mutex_unlock(&this->waiter->mt_deads);
		//pthread_mutex_destroy(&mt_state);
		return (1);
	}
	return (0);
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
		if(is_dead(this))
			return (NULL);

		//usleep(700000);	
	}
	return (NULL) ;
}