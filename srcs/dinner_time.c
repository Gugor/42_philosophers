/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:01:50 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/25 14:58:34 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/**
 * @brief It updates the elapsed time for a given value.
*/
int	update_elapsed_time_to(time_t *new, time_t start, char precision)
{
    struct timeval		tv;
    struct timezone		*tz;

    if(gettimeofday(&tv, &tz) < 0)
        return (errno);
    *new =  get_elapsed_time(start, 'm'); 
	return (0);
}
/**
 * @brief It returns the current time with the prcision given seconds 
 * or microseconds.
 * @return `{time_t (long)}`
*/
time_t  get_current_time(char precision)
{
	struct timeval		tv;
	struct timezone		*tz;

	if(gettimeofday(&tv, &tz) < 0)
		return (errno);
	if (precision == 's' || precision == 'S')
		return ((tv.tv_sec + (tv.tv_usec / 100000)));
	if (precision == 'm' || precision == 'M')
		return ((tv.tv_sec * 100000) + tv.tv_usec);
	return (-1);
}

/**
 * @brief It gets the time passed between two moments. You
 * can set the precision in seconds o microseconds.
*/
time_t	get_elapsed_time(time_t start, char precision)
{
    time_t end;
	
	end = get_current_time(precision);
	return (end - start);
}

/**
 * @brief It stablish the new tiem for dinner. It should be used
 * when initalizing dinner;
*/
int set_dinner_time(t_dinner *dinner)
{
    struct timeval tv;
    struct timezone *tz;

    if(gettimeofday(&tv, &tz) < 0)
        return (errno);
    dinner->start_tm = get_current_time('m');
    return (0);
}
