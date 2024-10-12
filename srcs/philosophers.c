/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:02:01 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/13 00:06:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <string.h>

static int	check_death(t_philo *philo, t_waiter *waiter)
{
	int64_t		interval;

	interval = get_elapsed_time(get_philo_lstml(philo), 'm');
	if (interval > philo->time_to_die * 1000L + 1000L
		&& get_philo_state(philo) != EATING)
	{
		set_waiter_state(waiter, ENDED);
		usleep(1000);
		print_format_death(philo, interval, &waiter->mt_print);
		return (1);
	}
	return (0);
}

static void	waitering(t_philo *philos, t_waiter *waiter, int num)
{
	int		indx;

	set_waiter_state(waiter, DINNING);
	indx = -1;
	while (++indx < num)
	{
		if (check_death(&philos[indx], philos[indx].waiter))
			return ;
		if (get_waiter_pfull(waiter) >= num)
			return ;
		if (indx == num - 1)
			indx = -1;
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

	if (init_dinner(ac, av, &dinner, &settings))
		exit (EXIT_FAILURE);
	init_waiter(&waiter, &dinner);
	if (register_philos(&dinner, &waiter) < 0)
	{
		clear_dinner(&dinner, 0);
		return (EXIT_FAILURE);
	}
	waitering(dinner.philos, &waiter, settings.num_of_philos);
	unregister_philos(dinner.philos, settings.num_of_philos);
	clear_dinner(&dinner, 1);
	return (EXIT_SUCCESS);
}
