/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:01:50 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/28 15:13:49 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/**
 * @brief It updates the elapsed time for a given value.
*/
int64_t   update_elapsed_time_to(int64_t *new, int64_t start, char precision)
{
    struct timeval		tv;
    struct timezone		*tz;

    if(gettimeofday(&tv, &tz) < 0)
        return (errno);
    *new =  get_elapsed_time(start, precision); 
	return (*new);
}
/**
 * @brief It returns the current time with the prcision given seconds 
 * or microseconds.
 * @return `{time_t (long)}`
*/
int64_t  get_current_time(char precision)
{
	struct timeval		tv;
	struct timezone		*tz;

	if(gettimeofday(&tv, &tz) < 0)
		return (errno);
	if (precision == 's' || precision == 'S')
		return ((tv.tv_sec + (tv.tv_usec / 1000000L)));
	if (precision == 'm' || precision == 'M')
		return ((tv.tv_sec * 1000000L) + tv.tv_usec);
	if (precision == 'c' || precision == 'C')
		return (((tv.tv_sec * 1000000L) + tv.tv_usec) / 1000L);
	return (-1);
}

/**
 * @brief It gets the time passed between two moments. You
 * can set the precision in seconds o microseconds.
*/
int64_t	get_elapsed_time(int64_t start, char precision)
{
    int64_t end;
	
	end = get_current_time(precision);
	return (end - start);
}

/**
 * @brief It stablish the new tiem for dinner. It should be used
 * when initalizing dinner;
*/
int64_t set_dinner_time(t_dinner *dinner)
{
    struct timeval tv;
    struct timezone *tz;

    if(gettimeofday(&tv, &tz) < 0)
        return (errno);
    dinner->start_tm = get_current_time('m');
    return (0);
}
