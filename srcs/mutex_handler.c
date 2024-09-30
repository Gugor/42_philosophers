/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:48:15 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/30 19:08:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_dinner_state(t_philo *philo)
{
	t_dinner_state	state;
	int				deads;
	is_dead(philo);
	deads = 0;
	pthread_mutex_lock(&philo->waiter->mt_state);
	state = philo->waiter->state;
	pthread_mutex_unlock(&philo->waiter->mt_state);
	pthread_mutex_lock(&philo->waiter->mt_deads);
	deads = philo->waiter->deads;
	pthread_mutex_unlock(&philo->waiter->mt_deads);
	if (state == ENDED || philo->state == FULL)
		return (0);
	return (1);
}

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
 * @brief It uses a mutex to set the philosopher state.
 * @returns `{void}`
*/
void set_dead_state(t_waiter *waiter, int indx)
{
	pthread_mutex_lock(&waiter->mt_deads);
	waiter->deads = indx;
	pthread_mutex_unlock(&waiter->mt_deads);
}

/**
 * @brief It sets a mutex for the fork of the given hand.
 * @returns `{void}`
*/
int get_fork(t_philo *this, t_ph_hand hand)
{
	if (hand == LEFT)
		pthread_mutex_lock(this->left_hand);
	if (hand == RIGHT)
		pthread_mutex_lock(this->right_hand);
	if (hand == LEFT)
		print(this, FORK_LEFT);
	if (hand == RIGHT)
		print(this, FORK_RIGHT);
	return (1);
}

/**
 * @brief It sets a mutex for the fork of the given hand.
 * @returns `{void}`
*/
void put_fork(t_philo *this, t_ph_hand hand)
{
	if (hand == LEFT)
		pthread_mutex_unlock(this->left_hand);
	if (hand == LEFT)
		print(this, PUT_LEFT);
	if (hand == RIGHT)
		pthread_mutex_unlock(this->right_hand);
	if (hand == RIGHT)
		print(this, PUT_RIGHT);
}
