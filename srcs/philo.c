/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:47:53 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/25 18:16:58 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *dinning(void *data)
{
	t_philo *this;

	this = (t_philo *)data;
    printf("Dinner state: %u\n", this->state);
	while(this->waiter->state != ENDED)
	{
		if (update_elapsed_time_to(&this->time_alive, this->time_last_meal, 'm') > (this->time_to_die * 1000L))
		{
			printf("Philo as died! ☠️\n");
			this->state = DIED;
			break;
		}
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

/**
 * @brief It creates as philosophers and its associated threads, as
 * well as 
*/
int create_philos(t_dinner *dinner, t_waiter *waiter)
{
	t_settings	*stts;
	t_philo		*philos;
	int			indx;


	stts = dinner->settings;
	philos = (t_philo *)malloc(sizeof(t_philo) * stts->num_of_philos);
	if (!philos)
		return (1);
	indx = -1;
	while (++indx < stts->num_of_philos)
	{
		init_philo(indx, &philos[indx], dinner->settings, waiter);
		pthread_create(&(philos[indx].pthread), NULL, dinning, &philos[indx]);
	}
	dinner->philos = philos;
	indx = -1;
	while(++indx < stts->num_of_philos)
		pthread_join(philos[indx].pthread, NULL);
	return (0);
}

/**
 * @brief
*/
t_philo *init_philo(int indx, t_philo *philo, t_settings *stts, t_waiter *wtr)
{
    if (!philo)
        return (NULL);
    philo->waiter = wtr;
    philo->indx = indx;
    philo->ld_hand = indx % 2;
    philo->left_hand = NULL;
    philo->right_hand = NULL;
    philo->state = STOPED;
    philo->time_to_die = stts->time_to_die;
    philo->time_to_eat = stts->time_to_die;
    philo->time_to_sleep = stts->time_to_die;
    philo->times_eaten = 0; 
    philo->times_slept = 0; 
    philo->times_thought = 0; 
    philo->time_last_meal = 0;
    philo->birth = get_current_time('m');
    philo->time_alive = 0;
    return (philo);
}
