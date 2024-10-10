/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:34:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/10 19:10:43 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* @brief It add one more philo full.
*/
void	set_waiter_pfull(t_waiter *waiter)
{
	pthread_mutex_lock(&waiter->mt_phfull);
	waiter->philos_full++;
	pthread_mutex_unlock(&waiter->mt_phfull);
}

/**
 * @brief It uses a mutex to set the philosopher state.
 * @returns `{void}`
*/
void	set_waiter_state(t_waiter *waiter, t_dinner_state newstate)
{
	pthread_mutex_lock(&waiter->mt_state);
	waiter->state = newstate;
	pthread_mutex_unlock(&waiter->mt_state);
}

/**
 * @brief It uses a mutex to set the philosopher state.
 * @returns `{void}`
*/
void	set_waiter_whoisdead(t_waiter *waiter, int indx, int64_t time)
{
	pthread_mutex_lock(&waiter->mt_whoisdead);
	waiter->whoisdead = indx;
	waiter->time_of_death = time;
	pthread_mutex_unlock(&waiter->mt_whoisdead);
}
