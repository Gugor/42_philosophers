/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:33:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/08 20:57:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Free double pointer data
*/
void	destroy_forks(pthread_mutex_t **data, int amount)
{
	pthread_mutex_t	*tmp;

	if (!data)
		return ;
	tmp = *data;
	while (--amount >= 0)
		pthread_mutex_destroy(&tmp[amount]);
	free(tmp);
	data = NULL;
}

void	clear_dinner(t_dinner *dinner, t_waiter *waiter)
{
	int	amount;

	amount = dinner->settings->num_of_philos;
	destroy_forks(&dinner->forks, amount);
	pthread_mutex_destroy(&waiter->mt_state);
	pthread_mutex_destroy(&waiter->mt_deads);
	pthread_mutex_destroy(&waiter->mt_print);
	pthread_mutex_destroy(&waiter->mt_start);
}
