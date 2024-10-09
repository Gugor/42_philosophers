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
		if (is_dead(philos[indx]))
		{
			set_waiter_state(waiter, ENDED);
			return (1);
		}
	}
	return (0);
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
