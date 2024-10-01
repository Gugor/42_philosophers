/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/01 17:22:53 by hmontoya         ###   ########.fr       */
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
    printf(" [min_meals_to_eat]%s\n", RESET);
    printf("    [NUM_OF_PHILOS] %s      > 0   %s && %s≤ 200%s\n",
    BLD_MAGENTA, RESET, BLD_MAGENTA, RESET);
    printf("    [TIME_TO_DIE] %s        > 0 ms%s && %s≥ 60 ms%s\n",
    BLD_MAGENTA, RESET, BLD_MAGENTA, RESET);
    printf("    [TIME_TO_EAT] %s        > 0 ms%s && %s≥ 60 ms%s\n",
    BLD_MAGENTA, RESET, BLD_MAGENTA, RESET);
    printf("    [TIME_TO_SLEEP] %s      > 0 ms%s && %s≥ 60 ms%s\n",
    BLD_MAGENTA, RESET, BLD_MAGENTA, RESET);
    printf("    [min_meals_to_eat] %s   > 0   %s && %s≤ 999999999%s\n",
    BLD_MAGENTA, RESET, BLD_MAGENTA, RESET);
    printf("\n\n");
}

/**
 * @brief 
*/
void print_input_err(int err)
{
    printf("\n");
    if (err == 1)
        printf("%sWrong%s number of arguments.\n", RED, RESET);
    if (err == 2)
        printf(" %s- 🧔‍♂️  [num_of_philos]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 3)
        printf(" %s- ⚰️  [time_to_die]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 4)
        printf(" %s- 🍽️  [time_to_eat]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 5)
        printf(" %s- 🛌  [time_to_sleep]%s should be a valid positive number", 
        BLD_WHITE, RESET);
    if (err == 6)
        printf(" %s- 🍽️  [min_meals_to_eat]%s should be a valid positive number",
        BLD_WHITE, RESET);
    if (err > 1 && err < 7)
        printf("%s > 0 && ≤ 999999999%s\n", BLD_GREEN, RESET);
    printf("\n");
}

/**
 * @brief 
*/
void print_settings_range_err(int err)
{
    printf("\n");
    if (err == 21)
        printf("- An input value %scannot be 0%s in order the simulation to work\n",
        BLD_RED, RESET);
    if (err == 22)
        printf("- You should not try to simulate with more than %s200%s philosophers\n",
        BLD_RED, RESET);
    if (err == 23)
        printf(MS_TIME_DIE_ERR_MSG, BLD_WHITE, RESET, BLD_RED, RESET);
    if (err == 24)
        printf(MS_TIME_EAT_ERR_MSG, BLD_WHITE, RESET, BLD_RED, RESET);
    if (err == 25)
        printf(MS_TIME_SLEEP_ERR_MSG, BLD_WHITE, RESET, BLD_RED, RESET);
    printf("\n");
}

/**
 * @brief It prints the error message given as parameter.
 * @param err `{int}` a code representing the error to print.
 * @returns `{void}`
*/
void print_settings_err(int err)
{
    if (err == 0)
        return ;
    if (err > 0 && err < 7)
        print_input_err(err);
    if (err > 20)
        print_settings_range_err(err);
    printf_usage_error();
}
