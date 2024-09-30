/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:12:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/30 18:55:24 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Is as usleep function but we can break in case a philo dies.
 * @returns `{int}`
 * - 0 for not break
 * - 1 for  break
*/
int philo_uwait(int64_t mcs, t_philo *philo)
{
   	int64_t	start;
	int64_t remanent;
	int64_t elapsed;
	size_t	indx;

	start = get_current_time('m');
	elapsed = get_elapsed_time(start, 'm');
	remanent = mcs - elapsed;
	if (remanent > 1000)
		usleep(remanent / 2);
	indx = 1;
	while (elapsed < mcs)
	{
		if(is_dead(philo))	
			return (1);
		elapsed = get_elapsed_time(start, 'm');
		remanent = mcs - elapsed;
		if (remanent > 1000)
			usleep(remanent / 2);
	}
	return (0);
}