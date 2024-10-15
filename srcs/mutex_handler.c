/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:48:15 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/15 11:01:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It checks dinner current dinner state.
 * @returns `{int}`
 * `0 if dinner has finished`
 * `1 if dinner is still running`
 */
int	check_dinner_state(t_philo *philo)
{
	t_dinner_state	state;

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
void	get_forks(t_philo *this)
{
	pthread_mutex_lock(this->right_hand);
	print(this, FORK_RIGHT);
	pthread_mutex_lock(this->left_hand);
	print(this, FORK_LEFT);
}

/**
 * @brief It sets a mutex for the fork of the given hand.
 * @returns `{void}`
*/
void	put_forks(t_philo *this)
{
	pthread_mutex_unlock(this->right_hand);
	print(this, PUT_RIGHT);
	pthread_mutex_unlock(this->left_hand);
	print(this, PUT_LEFT);
}
