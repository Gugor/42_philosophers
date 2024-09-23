/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/23 17:13:14 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void printf_usage_error()
{
    printf(" %sUsage:%s ./philosophers", BLD_WHITE, RESET); 
    printf(" %s[NUM_OF_PHILOS]", WHITE); 
    printf(" [TIME_TO_DIE]");
    printf(" [TIME_TO_EAT]");
    printf(" [TIME_TO_SLEEP]");
    printf(" [MAX_MEALS_TO_EAT]%s", RESET);
    printf("\n\n");
}
/**
 * @brief It prints the error message given as parameter.
 * @param err `{int}` a code representing the error to print.
 * @returns `{void}`
*/
void print_settings_err(int err)
{
    printf("\n");
    if (err == 1)
        printf("%sWrong%s number of arguments.\n", RED, RESET);
    if (err == 2)
        printf(" %s🧔‍♂️[num_of_philos]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 22)
        printf("You should not try with more than %s200%s philosophers",
        BLD_RED, RESET);
    if (err == 3)
        printf(" %s⚰️[time_to_die]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 4)
        printf(" %s🍽️[time_to_eat]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 5)
        printf(" %s🛌[time_to_sleep]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 6)
        printf(" %s🍽️[max_meals_to_eat]%s should be a valid positive number",
        BLD_WHITE, RESET);
    if (err > 1 && err != 22)
        printf(" <= 999999999\n");
    printf("\n");
    printf_usage_error();
}
