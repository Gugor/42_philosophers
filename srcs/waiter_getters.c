/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:34:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/01 18:06:19 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/*
* @brief It add one more philo full.
*/
int get_waiter_pfull(t_waiter *waiter)
{
	int full;

	pthread_mutex_lock(&waiter->mt_phfull);
	full = waiter->philos_full;
	pthread_mutex_unlock(&waiter->mt_phfull);
	return (full);
}

/**
 * @brief It gets the dinner state
 * @returns `{t_dinner_state}` 
 * an integer representing the 
*/
int get_waiter_state(t_waiter *wtr)
{
	t_dinner_state state;
	pthread_mutex_lock(&wtr->mt_state);
	state = wtr->state; 
	pthread_mutex_unlock(&wtr->mt_state);
	return (state);
}

/**
 * @brief It gets who is dead
*/
int get_whoisdead(t_waiter *waiter)
{
	int whoisdead;

	pthread_mutex_lock(&waiter->mt_deads);
		whoisdead = waiter->whoisdead;
	pthread_mutex_unlock(&waiter->mt_deads);
	return (whoisdead);
}
