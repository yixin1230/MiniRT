/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 12:57:37 by yizhang       #+#    #+#                 */
/*   Updated: 2024/01/30 16:17:04 by svan-has      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

t_vec	unit_vector(t_vec v)
{
	float	len;
	t_vec	ret;

	len = vec_len(v);
	ret = set_vec(v.x / len, v.y / len, v.z / len);
	return (ret);
}

t_vec	calc_hitpoint(t_ray r, float t)
{
	t_vec	hitpoint;

	hitpoint.x = r.orig.x + t * r.dir.x;
	hitpoint.y = r.orig.y + t * r.dir.y;
	hitpoint.z = r.orig.z + t * r.dir.z;
	return (hitpoint);
}

t_vec	mult(t_vec v1, t_vec v2)
{
	t_vec	vector;

	vector.x = v1.x * v2.x;
	vector.y = v1.y * v2.y;
	vector.z = v1.z * v2.z;
	return (vector);
}

t_vec	mult_fact(t_vec vec, float fact)
{
	t_vec	vector;

	vector.x = vec.x * fact;
	vector.y = vec.y * fact;
	vector.z = vec.z * fact;
	return (vector);
}
