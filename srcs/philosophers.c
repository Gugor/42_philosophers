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

static int	check_if_died(t_dinner *dinner, int num)
{
	int		indx;
	t_philo	*philos;

	indx = -1;
	philos = dinner->philos;
	while (++indx < num)
	{
		if (is_dead(&philos[indx]))
		{
			pthread_mutex_lock(&dinner->mt_waiter);
			set_waiter_state(philos[indx].waiter, ENDED);
			pthread_mutex_unlock(&dinner->mt_waiter);
			print(&philos[indx], DIED);
			return (1);
		}
	}
	return (0);
}

void	waitering(t_dinner *dinner, t_waiter *waiter)
{
	t_philo	*philos;
	int		indx;

	pthread_mutex_lock(&dinner->mt_waiter);
	set_waiter_state(waiter, DINNING);
	pthread_mutex_unlock(&dinner->mt_waiter);
	philos = dinner->philos;
	indx = -1;
	while (1)
	{
		if (check_if_died(dinner,
				dinner->settings->num_of_philos))
			return ;
		pthread_mutex_lock(&dinner->mt_waiter);
		if (get_waiter_pfull(waiter) >= dinner->settings->num_of_philos)
		{
			pthread_mutex_unlock(&dinner->mt_waiter);
			return ;
		}
		pthread_mutex_unlock(&dinner->mt_waiter);
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
	
	/*if (get_whoisdead(&waiter) > -1)
		print_format_death(&dinner.philos[get_whoisdead(&waiter)],
			" has died❕ 🪦 ⚰💀" , &waiter.mt_print);*/
	/*if (get_waiter_pfull(&waiter) == settings.num_of_philos)
		set_waiter_state(&waiter, ENDED);*/
	update_elapsed_time_to(&dinner.dinner_duration, dinner.start_tm, 'm');
	//clear_dinner(&dinner, &waiter);
	return (EXIT_SUCCESS);
}
