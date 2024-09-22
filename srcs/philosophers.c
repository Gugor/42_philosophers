/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:02:01 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/22 21:06:29 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/**
 * @brief It parse the arguments passed to the program
 * and initialize the struct of settings.
 * @param ac `{int}` the number of arguments in the program.
 * @param av `{char}` the arguments of the program.
 * @param settings `{t_settings}` a pointer to the stuct that saves
 * the settings of the program.
 * @returns `{int}`
 * - 0 if no errors
 * - 1 if not correct number of arguments
 * - 2 if `num_of_philos` is not a valid digit
 * - 3 if `time_to_die` is not a valid digit
 * - 4 if `time_to_eat` is not a valid digit
 * - 5 if `time_to_sleep` is not a valid digit
 * - 6 if `max_meals_to_eat` is not a valid digit
*/
int	init_settings(int ac, char **av, t_settings *settings)
{
	if (is_valid_digit(av[1]))
		settings->num_of_philos = ft_atoi(av[1]);
	else
		return (2);
	if (is_valid_digit(av[2]))
		settings->time_to_die = ft_atoi(av[2]);
	else
		return (3);
	if (is_valid_digit(av[3]))
		settings->time_to_eat = ft_atoi(av[3]);
	else
		return (4);
	if (is_valid_digit(av[4]))
		settings->time_to_sleep = ft_atoi(av[4]);
	else
		return (5);
	if (ac == 6)
	{
		printf("%i", ac);
		if(is_valid_digit(av[5]))
			settings->max_meals_to_eat = ft_atoi(av[5]);
		else
			return (6);
	}
	return (0);
}
/*
int	create_forks(t_dinner *dinner)
{
	int	indx;
	int	max_forks;

	indx = -1;
	max_forks = dinner->settings->num_of_philos;
	while(indx )
	{

	}

}
*/


int init_dinner(int ac, char **av, t_dinner *dinner, t_settings *settings)
{
	int sttngs_err;

	(void)dinner;
	if (ac < 4)
	{
		print_settings_err(1);
		return (1);
	}
	sttngs_err = init_settings(ac, av, settings);
	if (sttngs_err)
	{
		print_settings_err(sttngs_err);
		return (sttngs_err);
	}
	//create_forks();
	//create_philos
	return (0);
}
#include <string.h>
/**
 * @brief It's a program that create multiple threads. This thread are Philosophers 
 * that eat, sleep, think and died. 
 */
int main(int ac, char **av)
{
	t_dinner	dinner; 
	t_settings	settings;
	//char **av2 = (char **)calloc(sizeof(char *), 6);

	init_dinner(ac, av, &dinner, &settings);
	//create_forks();
	//create_philosophers();
	//observe_dinner();
	//clear_memory();
	return (0);
}