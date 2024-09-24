/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:02:01 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/24 19:13:17 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



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

	if (init_dinner(ac, av, &dinner, &settings))
		exit (EXIT_FAILURE);
	//create_philosophers();
	//observe_dinner();
	//clear_memory(dinner);
	return (0);
}