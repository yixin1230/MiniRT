/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:17:48 by yizhang       #+#    #+#                 */
/*   Updated: 2023/10/10 11:21:38 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "mlx42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <string.h>

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;

}t_vec;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}t_color;

int get_rgba(int r, int g, int b, int a);
#endif