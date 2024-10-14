/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:20:17 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/13 00:21:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It creates the necesary forks to be used by the philosophers.
 * This forks are initialized mutex.
 * @returns `{int}`
*/
int	create_forks(pthread_mutex_t **pforks, int amount)
{
	int				indx;
	pthread_mutex_t	*forks;

	indx = -1;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * amount);
	if (!forks)
		return (-1);
	while (++indx < amount)
	{
		if (pthread_mutex_init(&forks[indx], NULL))
			return (1);
		printf("Fork %i (%p)\n", indx, &forks[indx]);
	}
	printf("\n");
	*pforks = forks;
	return (0);
}

/**
 * @brief Initialize waiter
*/
void	init_waiter(t_waiter *wtr, t_dinner *dinner)
{
	wtr->state = PREPARING;
	wtr->dinner_start = dinner->start_tm;
	wtr->whoisdead = -1;
	wtr->philos_full = 0;
	wtr->num_of_philos = dinner->settings->num_of_philos;
	pthread_mutex_init(&wtr->mt_state, NULL);
	pthread_mutex_init(&wtr->mt_print, NULL);
	pthread_mutex_init(&wtr->mt_whoisdead, NULL);
	pthread_mutex_init(&wtr->mt_start, NULL);
	pthread_mutex_init(&wtr->mt_phfull, NULL);
}

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
 * - 6 if `min_meals_to_eat` is not a valid digit
*/
int	init_settings(int ac, char **av, t_settings **sts)
{
	int	err;

	err = 0;
	if (set_sttng_val(&(*sts)->num_of_philos, av[1], 2) > 1)
		return (2);
	if (set_sttng_val(&(*sts)->time_to_die, av[2], 3) > 1)
		return (3);
	if (set_sttng_val(&(*sts)->time_to_eat, av[3], 4) > 1)
		return (4);
	if (set_sttng_val(&(*sts)->time_to_sleep, av[4], 5) > 1)
		return (4);
	if (ac == 6)
	{
		if (set_sttng_val(&(*sts)->min_meals_to_eat, av[5], 6) > 1)
			return (6);
	}
	else
		(*sts)->min_meals_to_eat = -1;
	err = check_settings(*sts);
	if (err > 0)
		return (err);
	return (0);
}

/**
 * @brief It initialize the structur that represents the dinner party.
*/
int	init_dinner(int ac, char **av, t_dinner *dinner, t_settings *settings)
{
	int			sttngs_err;

	(void)dinner;
	if (ac <= 4 || ac > 6)
	{
		print_settings_err(1);
		return (1);
	}
	pthread_mutex_init(&dinner->mt_waiter, NULL);
	set_dinner_time(dinner);
	sttngs_err = init_settings(ac, av, &settings);
	if (settings->min_meals_to_eat == 0)
	{
		print_settings_err(sttngs_err);
		return (1);
	}
	dinner->settings = settings;
	if (sttngs_err)
	{
		print_settings_err(sttngs_err);
		return (sttngs_err);
	}
	if (create_forks(&dinner->forks, settings->num_of_philos))
		destroy_forks(&dinner->forks, settings->num_of_philos);
	return (0);
}
