/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:21:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/15 11:59:05 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_format_fork(t_philo *philo, char *msg,
	pthread_mutex_t *mt_print)
{
	int64_t			time;
	t_philo_state	state;

	pthread_mutex_lock(mt_print);
	printf("%s|%ldus|%s ", BLD_BLACK,
		get_elapsed_time(philo->waiter->dinner_start, 'm'), RESET);
	time = get_elapsed_time(philo->time_last_meal, 'm');
	printf("🧔 %s[%lims]%s %sPhilo%s %i ", BLD_YELLOW, time / 1000L, RESET,
		BLD_MAGENTA, RESET, philo->indx + 1);
	state = get_philo_state(philo);
	if (state == FORK_LEFT || state == PUT_LEFT)
		printf("%s (%p)", msg, &(*philo->left_hand));
	if (state == FORK_RIGHT || state == PUT_RIGHT)
		printf("%s (%p)", msg, &(*philo->right_hand));
	printf("\n");
	pthread_mutex_unlock(mt_print);
}

void	print_format_death(t_philo *philo, int64_t tod,
		pthread_mutex_t *mt_print)
{
	pthread_mutex_lock(mt_print);
	printf("%s|%ldus|%s ", BLD_BLACK,
		get_elapsed_time(philo->waiter->dinner_start, 'm'), RESET);
	printf("🧔 %s[%lims]%s %sPhilo%s %i ", BLD_YELLOW, (tod) / 1000L, RESET,
		BLD_MAGENTA, RESET, philo->indx + 1);
	printf(" has died! 🪦 ⚰💀\n");
	pthread_mutex_unlock(mt_print);
}

static void	print_format(t_philo *philo, char *msg, pthread_mutex_t *mt_print)
{
	int64_t	time;

	pthread_mutex_lock(mt_print);
	printf("%s|%ldus|%s ", BLD_BLACK,
		get_elapsed_time(philo->waiter->dinner_start, 'm'), RESET);
	time = get_elapsed_time(philo->time_last_meal, 'm');
	printf("🧔 %s[%lims]%s %sPhilo%s %i ", BLD_YELLOW, time / 1000L, RESET,
		BLD_MAGENTA, RESET, philo->indx + 1);
	printf("%s\n", msg);
	pthread_mutex_unlock(mt_print);
}

void	print(t_philo *philo, t_philo_state state)
{
	if (get_waiter_state(philo->waiter) == ENDED
		|| get_philo_state(philo) == DIED)
		return ;
	set_philo_state(philo, state);
	if (state == EATING)
		print_format(philo, " is eating❕ 🥣", &philo->waiter->mt_print);
	if (state == SLEEPING)
		print_format(philo, " is sleeping❕ 😪💤", &philo->waiter->mt_print);
	if (state == THINKING)
		print_format(philo, " is thinking❕ 🤔💭", &philo->waiter->mt_print);
	if (state == FULL)
		print_format(philo, " is full❕ 🥣🫄", &philo->waiter->mt_print);
	if (state == FORK_LEFT)
		print_format_fork(philo, " took left fork❕ 🫱",
			&philo->waiter->mt_print);
	if (state == FORK_RIGHT)
		print_format_fork(philo, " took right fork❕ 🫲",
			&philo->waiter->mt_print);
	if (state == PUT_LEFT)
		print_format_fork(philo, " put left fork!🫳", &philo->waiter->mt_print);
	if (state == PUT_RIGHT)
		print_format_fork(philo, " put right fork!🫳", &philo->waiter->mt_print);
}
