/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:02:01 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/01 17:32:34 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <string.h>

/**
 * @brief It's a program that create multiple threads. This thread are Philosophers 
 * that eat, sleep, think and died. 
 */
int main(int ac, char **av)
{
	t_dinner	*dinner; 
	t_settings	*settings;
	t_waiter	waiter;

	dinner = (t_dinner *)malloc(sizeof(t_dinner));
	settings = (t_settings *)malloc(sizeof(t_settings));
	if (init_dinner(ac, av, dinner, settings))
	{
		free(settings);
		free(dinner);
		exit (EXIT_FAILURE);
	}
	init_waiter(&waiter, dinner);
	register_philos(dinner, &waiter);
	while (get_waiter_state(&waiter) == DINNING)
			;;
	if (get_whoisdead(&waiter) > -1)
		print_format_death(&dinner->philos[get_whoisdead(&waiter)],
		" has died❕ 🪦 ⚰💀" , &waiter.mt_print);
	update_elapsed_time_to(&dinner->dinner_duration, dinner->start_tm, 'm');
	printf("%sDinner duration:%s %ld %sms%s\n", MAGENTA, RESET, dinner->dinner_duration / 1000L, BLD_YELLOW, RESET);
	clear_dinner(&dinner, &waiter);
	return (EXIT_SUCCESS);
}
