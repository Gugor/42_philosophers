/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:47:53 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/09 19:31:31 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It creates as philosophers and its associated threads, as
 * well as 
*/
int register_philos(t_dinner *dinner, t_waiter *waiter)
{
	t_settings	*stts;
	t_philo		*philos;
	int			indx;

	stts = dinner->settings;
	if (stts->num_of_philos == 1)
	{
		printf("%sPhilo 0%s  has died❕ 🪦 ⚰💀\n", BLD_MAGENTA, RESET);
		return (-1);
	}
	philos = (t_philo *)malloc(sizeof(t_philo) * stts->num_of_philos);
	if (!philos)
		return (1);
	indx = -1;
	while (++indx < stts->num_of_philos)
	{
		init_philo(indx, &philos[indx], dinner, waiter);
		pthread_create(&(philos[indx].pthread), NULL, dinning, &philos[indx]);
	}
	dinner->philos = philos;
	set_waiter_state(waiter, DINNING);
	indx = -1;
	while (++indx < stts->num_of_philos)
		pthread_join(philos[indx].pthread, NULL);
	return (0);
}

/**
 * @brief It selects the forks a philosopher needs to pick depending
 * if its left or right handed.
 * @returns `{void}`
*/
static void	select_fork_for_hands(pthread_mutex_t *forks,
	t_philo *owner, int num)
{
	owner->left_hand = &forks[owner->indx];
	owner->right_hand = &forks[(owner->indx + 1) % num];
}

/**
 * @brief
*/
t_philo	*init_philo(int indx, t_philo *philo, t_dinner *dinner, t_waiter *wtr)
{
	t_settings	*stts;

	if (!philo)
		return (NULL);
	stts = dinner->settings;
	philo->waiter = wtr;
	philo->indx = indx;
	philo->leader_hand = indx % 2;
	select_fork_for_hands(dinner->forks, philo, stts->num_of_philos);
	philo->state = STOPED;
	philo->time_to_die = stts->time_to_die;
	philo->time_to_eat = stts->time_to_eat;
	philo->time_to_sleep = stts->time_to_sleep;
	philo->min_meals_to_eat = stts->min_meals_to_eat;
	philo->times_eaten = 0; 
	philo->times_slept = 0; 
	philo->times_thought = 0; 
	philo->time_last_meal = get_current_time('m');
	philo->birth = get_current_time('m');
	philo->time_alive = 0;
	return (philo);
}
