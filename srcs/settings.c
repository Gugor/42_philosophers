/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:09:52 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/10 19:12:09 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief It checks if the values of the settings are
 * valid.
 * @returns `{int}`
*/
int	check_settings(t_settings *sts)
{
	int	val;

	val = sts->num_of_philos;
	if (check_sttng(val, (val > 200), 22) > 0)
		return (22);
	val = sts->time_to_die;
	if (check_sttng(val, (val < 60), 23) > 0)
		return (23);
	val = sts->time_to_eat;
	if (check_sttng(val, (val < 60), 24) > 0)
		return (24);
	val = sts->time_to_sleep;
	if (check_sttng(val, (val < 60), 25) > 0)
		return (25);
	val = sts->min_meals_to_eat;
	if (val > 0 && (check_sttng(val, val == 0, 21) > 0))
		return (21);
	return (0);
}

/**
 * @brief It checks if the condition is true, in the contrary 
 * returns the given error. Also checks if the input is bigger than 0.
 * @return `{int}`
 * `- 0 no errors`
 * `- > 0 condition doesn't true.`
 * `- 7 if "set" is equals to 0.`
*/
int	check_sttng(int set, int condition, int err)
{
	if (set == 0)
		return (21);
	if (condition)
		return (err);
	return (0);
}

/**
 * @brief It sets the value of a setting, and checks if the value
 * is valid. Returns an error in case the value is not a valid number.
 * @returns `{int}`
 * `0 for no errors`
 * `!0 if the set value is not valid`
*/
int	set_sttng_val(int *set, char *val, int err)
{
	if (is_valid_digit(val))
		*set = ft_atoi(val);
	else
		return (err);
	return (0);
}
