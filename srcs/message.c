/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:21:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/27 18:44:47y hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void print_format_fork(t_philo *philo, char *msg, pthread_mutex_t *mt_print)
{
    int64_t time;

    pthread_mutex_lock(mt_print);
    printf("%s|%ld|%s ", BLD_BLACK, 
        get_elapsed_time(philo->waiter->dinner_start, 'm'), RESET);
    time = get_elapsed_time(philo->time_last_meal, 'm');
    printf("🧔 %s[%li]%s %sPhilo%s %i ", BLD_YELLOW, time / 1000L, RESET , 
    BLD_MAGENTA, RESET, philo->indx);
	if (philo->leader_hand == LEFT && philo->state == PUT_LEFT)
    	printf("%s  LEFTHANDED(%p)",msg, &(*philo->left_hand));
	if (philo->leader_hand == LEFT && philo->state == PUT_RIGHT)
    	printf("%s  LEFTHANDED(%p)",msg, &(*philo->right_hand));
	if (philo->leader_hand == RIGHT && philo->state == PUT_LEFT)
    	printf("%s  RIGHTHANDED(%p)",msg, &(*philo->left_hand));
	if (philo->leader_hand == RIGHT && philo->state == PUT_RIGHT)
    	printf("%s  RIGHTHANDED(%p)",msg, &(*philo->right_hand));
	printf("\n");
    pthread_mutex_unlock(mt_print);
}

static void print_format(t_philo *philo, char *msg, pthread_mutex_t *mt_print)
{
    int64_t time;

    pthread_mutex_lock(mt_print);
    printf("%s|%ld|%s ", BLD_BLACK, 
        get_elapsed_time(philo->waiter->dinner_start, 'm'), RESET);
    time = get_elapsed_time(philo->time_last_meal, 'm');
    printf("🧔 %s[%li]%s %sPhilo%s %i ", BLD_YELLOW, time / 1000L, RESET , 
    BLD_MAGENTA, RESET, philo->indx);
    printf("%s\n",msg);
    pthread_mutex_unlock(mt_print);
}

void print(t_philo *philo, t_philo_state state)
{
    if (philo->waiter->state == ENDED)
        return ;
    if (state == EATING)
        print_format(philo, " is eating❕ 🥣", &philo->waiter->mt_print);
    if (state == SLEEPING)
        print_format(philo, " is sleeping❕ 😪💤", &philo->waiter->mt_print);
    if (state == THINKING)
        print_format(philo, " is thinking❕ 🤔💭", &philo->waiter->mt_print);
    if (state == DIED)
        print_format(philo, " has died❕ 🪦 ⚰💀", &philo->waiter->mt_print);
    if (state == FULL)
        print_format(philo, " is full❕ 🥣🫄", &philo->waiter->mt_print);
    if (state == FORK_LEFT)
        print_format(philo, " has taken left fork❕ 🫱", &philo->waiter->mt_print);
    if (state == FORK_RIGHT)
        print_format(philo, " has taken right fork❕ 🫲", &philo->waiter->mt_print);
    if (state == PUT_LEFT)
	{
		philo->state = PUT_LEFT;
        print_format_fork(philo, " has put down left fork! 🫳", &philo->waiter->mt_print);
	}
    if (state == PUT_RIGHT)
	{
		philo->state = PUT_RIGHT;
        print_format_fork(philo, " has put down right fork! 🫳", &philo->waiter->mt_print);
	}
}
