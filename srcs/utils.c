/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:07:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/23 17:06:29 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Checks if a given char is a valid digit.
*/
int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}
/**
 * @brief It checks if a given char is in the range of the spacess ASCII codes.
 * That is spaces, tabs and others.
*/
int ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
/**
 * @brief A custom function that replicates `atoi()` function.
*/
int ft_atoi(const char *str)
{
	int	result;
	int	is_neg;

	result = 0;
	is_neg = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg++;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			break ;
		result = result * 10 + (*str - 48);
		str++;
	}
	if (is_neg)
		return (-result);
	return (result);
}
int ft_strlen(char *str)
{
	int indx;

	indx = -1;
	while (str[++indx])
		;;
	return (indx);
}
/**
 * @brief It takes a string and tells if its a valid digit. Means has nothing
 * more than digits in the string.
*/
int is_valid_digit(char *str, int hasmaxval)
{
	int indx;

    if (!str)
        return (0);
	indx = -1;
	if (hasmaxval && ft_strlen(str) > 9)
		return (0);
    while(str[++indx])
        if (str[indx] && !ft_isdigit(str[indx]))
            return (0);
    return (1);
}
