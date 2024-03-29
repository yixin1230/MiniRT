/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-has <svan-has@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:09:59 by svan-has      #+#    #+#                 */
/*   Updated: 2024/01/23 17:32:00 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	error_exit(char *message)
{
	printf("Error\n%s\n", message);
	exit (1);
}

void	*null_check(void *check)
{
	if (!check)
		error_exit("Malloc error");
	return (check);
}
