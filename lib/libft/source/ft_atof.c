/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-has <svan-has@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:39:01 by svan-has      #+#    #+#                 */
/*   Updated: 2023/10/23 14:41:47 by svan-has      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

float	ft_atof(const char *str)
{
	int			i;
	float		neg;
	float		return_value;

	i = 0;
	neg = 1;
	return_value = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			neg = -1;
		i++;
	}
	while (ft_isdigit((int)str[i]) == 1)
	{
		return_value += str[i] - 48;
		if (ft_isdigit((int)str[i + 1]) == 0)
			break ;
		return_value *= 10;
		i++;
	}
	return (return_value * neg);
}
