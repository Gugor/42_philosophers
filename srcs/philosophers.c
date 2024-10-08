/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:02:01 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/08 20:42:44y hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <string.h>

int	check_if_died(t_philo **philos, t_waiter *waiter, int num)
{
	int	indx;

	indx = -1;
	while (++indx < num && philos[indx])
	{
		pthread_mutex_lock(&waiter->mt_print);
		printf("Philo %i is time from last meal %ld\n", philos[indx]->indx + 1, get_elapsed_time(philos[indx]->time_last_meal, 'c'));
		pthread_mutex_unlock(&waiter->mt_print);
		if (is_dead(philos[indx]))
		{
			set_waiter_state(waiter, ENDED);
			return (1);
		}
	}
	return (0);
}

void	*waitering_r(void *data)
{
	t_dinner	*dinner = (t_dinner *)data;
	t_waiter	*waiter = dinner->philos[0].waiter;

	pthread_mutex_lock(&waiter->mt_print);
	printf("Waiterng start\n");
	pthread_mutex_unlock(&waiter->mt_print);
	set_waiter_state(waiter, DINNING);
	while (get_waiter_state(waiter) != ENDED)
	{
		if (get_waiter_pfull(waiter) >= dinner->settings->num_of_philos
			|| check_if_died(&dinner->philos, waiter,
			dinner->settings->num_of_philos))
		{
			set_waiter_state(waiter, ENDED);
			return (NULL) ;
		}
		usleep(1);
	}
	return (NULL) ;
}

void	waitering(t_dinner *dinner, t_waiter *waiter)
{
	while (get_waiter_state(waiter) != ENDED)
	{
		if (get_waiter_pfull(waiter) >= dinner->settings->num_of_philos
			|| check_if_died(&dinner->philos, waiter,
			dinner->settings->num_of_philos))
		{
			set_waiter_state(waiter, ENDED);
			return ;
		}
		usleep(1);
	}
}

/**
 * @brief It's a program that create multiple threads. This thread
 * are Philosophers 
 * that eat, sleep, think and died. 
 */
int	main(int ac, char **av)
{
	t_dinner	dinner;
	t_settings	settings;
	t_waiter	waiter;
	pthread_t	waiterer;

	if (init_dinner(ac, av, &dinner, &settings))
		exit (EXIT_FAILURE);
	init_waiter(&waiter, &dinner);
	register_philos(&dinner, &waiter);
	pthread_create(&waiterer, NULL, &waitering_r, &dinner);
	pthread_detach(waiterer);
	//waitering(&dinner, &waiter);
	if (get_whoisdead(&waiter) > -1)
		print_format_death(&dinner.philos[get_whoisdead(&waiter)],
			" has died❕ 🪦 ⚰💀" , &waiter.mt_print);
	if (get_waiter_pfull(&waiter) == settings.num_of_philos)
		set_waiter_state(&waiter, ENDED);
	update_elapsed_time_to(&dinner.dinner_duration, dinner.start_tm, 'm');
	clear_dinner(&dinner, &waiter);
	return (EXIT_SUCCESS);
}
