/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:12:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/29 22:46:47 by hmontoya         ###   ########.fr       */
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
	//printf("PH[%i][0]ELAPSED TIME: %ld || REMAINING TIME %ld (%ld)\n", philo->indx, elapsed, remanent, mcs);
	if (remanent > 1000)
		usleep(remanent / 2);
	indx = 0;
	while (elapsed < mcs)
	{
		if(is_dead(philo))	
		{
			set_dead_state(philo->waiter);
			return (1);
		}
		elapsed = get_elapsed_time(start, 'm');
		remanent = mcs - elapsed;
		//printf("PH[%i][%zu]ELAPSED TIME: %ld || REMAINING TIME %ld (%ld)\n",philo->indx, ++indx, elapsed, remanent, mcs);
		if (remanent > 1000)
			usleep(remanent / 2);
	}
	return (0);
}