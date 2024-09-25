/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:47:53 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/25 15:40:39 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief
*/
t_philo *init_philo(int indx, t_philo *philo, t_settings *stts)
{
    if (!philo)
        return (NULL);
    philo->indx = indx;
    philo->ld_hand = indx % 2;
    philo->left_hand = NULL;
    philo->right_hand = NULL;
    philo->state = STOPED;
    philo->time_to_die = stts->time_to_die;
    philo->time_to_eat = stts->time_to_die;
    philo->time_to_sleep = stts->time_to_die;
    philo->times_eaten = 0; 
    philo->times_slept = 0; 
    philo->times_thought = 0; 
    philo->birth = get_current_time('m');
    philo->time_alive = 0;
    return (philo);
}
