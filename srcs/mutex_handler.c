/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:48:15 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/09 19:25:24 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dinner_state(t_philo *philo)
{
	t_dinner_state	state;

	is_dead(philo);
	pthread_mutex_lock(&philo->waiter->mt_state);
	state = philo->waiter->state;
	pthread_mutex_unlock(&philo->waiter->mt_state);
	if (state == ENDED || philo->state == FULL)
		return (0);
	return (1);
}

/**
 * @brief It sets a mutex for the fork of the given hand.
 * @returns `{void}`
*/
int get_fork(t_philo *this, t_ph_hand hand)
{
	if (hand == LEFT)
		print(this, FORK_LEFT);
	if (hand == LEFT)
		pthread_mutex_lock(this->left_hand);
	if (hand == RIGHT)
		print(this, FORK_RIGHT);
	if (hand == RIGHT)
		pthread_mutex_lock(this->right_hand);
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
