/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:01:50 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/24 20:56:33 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int update_philo_time(t_philo *philo)
{
    struct timeval tv;
    struct timezone *tz;

    if(gettimeofday(&tv, &tz) < 0)
        return (errno);
    philo->time_alive =  (tv.tv_sec * 1000000 + tv.tv_usec) - philo->birth; 
}

/**
 * @brief
*/
int set_dinner_time(t_dinner *dinner)
{
    struct timeval tv;
    struct timezone *tz;

    if(gettimeofday(&tv, &tz) < 0)
        return (errno);
    dinner->start_tm = tv.tv_sec * 1000000 + tv.tv_usec;
    return (0);
}

int update_dinner_time(t_dinner *dinner)
{
    struct timeval tv;
    struct timezone *tz;

    if(gettimeofday(&tv, tz) < 0)
        return (errno);
    dinner->dinner_duration = (tv.tv_sec * 1000000 + tv.tv_usec) - dinner->start_tm; 
    return (0);
}

