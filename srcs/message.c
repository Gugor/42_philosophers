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

static void print_format(t_philo *philo, char *msg, pthread_mutex_t *mt_print)
{
    int64_t time;

    time = get_elapsed_time(philo->time_last_meal, 'm') / 1000L;
    pthread_mutex_lock(mt_print);
    printf("%ld ", philo->time_last_meal);
    printf("%s[%li]%s %sPhilo%s %i ", BLD_YELLOW, time, RESET , 
    BLD_MAGENTA, RESET, philo->indx);
    printf("%s\n",msg);
    pthread_mutex_unlock(mt_print);
    /*
    write(1, "[", 1);
    write(1, time, sizeof(time));
    write(1, "]", 1);
    write(1, "Philo ", 6);
    write(1, indx, sizeof(indx));
    write(1, "msg\n", ft_strlen(msg));
    */
}

void print(t_philo *philo, t_philo_state state)
{
    if (state == EATING)
        print_format(philo, " is eating!\n", &philo->waiter->mt_print);
    if (state == SLEEPING)
        print_format(philo, " is sleeping!\n", &philo->waiter->mt_print);
    if (state == THINKING)
        print_format(philo, " is thinking!\n", &philo->waiter->mt_print);
    if (state == DIED)
        print_format(philo, " has died!\n", &philo->waiter->mt_print);
    if (state == FORK)
        print_format(philo, " has taken fork!\n", &philo->waiter->mt_print);
}