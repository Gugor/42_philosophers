/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:34:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/01 15:59:21 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It uses a mutex to set the philosopher state.
 * @returns `{void}`
*/
void set_waiter_state(t_waiter *waiter, t_dinner_state newstate)
{
	pthread_mutex_lock(&waiter->mt_state);
	waiter->state = newstate;
	pthread_mutex_unlock(&waiter->mt_state);
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
 * @brief It uses a mutex to set the philosopher state.
 * @returns `{void}`
*/
void set_dead_state(t_waiter *waiter, int indx)
{
	pthread_mutex_lock(&waiter->mt_deads);
	if (waiter->whoisdead < 0)
		waiter->whoisdead = indx;
	pthread_mutex_unlock(&waiter->mt_deads);
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
