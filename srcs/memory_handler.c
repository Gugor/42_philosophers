/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:33:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/24 19:13:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Free double pointer data
*/
void    destroy_forks(pthread_mutex_t **data, int amount)
{
    pthread_mutex_t *tmp;

    if (!data)
        return ;
    tmp = *data;
    while (--amount >= 0)
        pthread_mutex_destroy(&tmp[amount]);
    free(tmp);
    data = NULL;
}