/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/22 20:29:08 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_settings_err(int err)
{
    if (err == 1)
    {
        printf("Wrong number of arguments.\n");
        printf("Usage: ./philosophers [NUM_OF_PHILOS] [TIME_TO_DIE]\
        [TIME_TO_EAT] [TIME_TO_SLEEP] [MAX_MEALS_TO_EAT].\n");
    }
    if (err == 2)
        printf("%s[num_of_philos]%s should be a valid number", BLD_WHITE, RESET);
    if (err == 3)
        printf("%s[time_to_die]%s should be a valid number", BLD_WHITE, RESET);
    if (err == 4)
        printf("%s[time_to_eat]%s should be a valid number", BLD_WHITE, RESET);
    if (err == 5)
        printf("%s[time_to_sleep]%s should be a valid number", BLD_WHITE, RESET);
    if (err == 6)
        printf("%s[max_meals_to_eat]%s should be a valid number", BLD_WHITE, RESET);
}
