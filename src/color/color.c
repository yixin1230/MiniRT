/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sven <sven@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 10:19:24 by yizhang       #+#    #+#                 */
/*   Updated: 2024/01/31 17:15:20 by svan-has      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
bool    check_obj(t_data *data, t_ray *ray, int id)
{
    int i;
    i = 0;
    ray->t = -1;
    float min_dist;
    t_object   *tmp_obj;

    min_dist = INFINITY;
    while (i < data->object_num)
    {
        if (data->objects[i].type == sphere && \
        hit_sphere(&data->objects[i], ray) && data->objects[i].id != id)
        {
            compare_update_t(&data->objects[i], ray);
            if (ray->t < min_dist)
            {
                tmp_obj = &data->objects[i];
                min_dist = tmp_obj->t;
            }
           
            //return (true);
        }
        else if (data->objects[i].type == plane && \
        hit_plane2(&data->objects[i], ray, data) && data->objects[i].id != id)
        {
            compare_update_t(&data->objects[i], ray);
            if (ray->t < min_dist)
            {
                tmp_obj = &data->objects[i];
                min_dist = tmp_obj->t;
            }
            //return (true);
        }
        else if (data->objects[i].type == cylinder && \
        hit_cylinder(&data->objects[i], ray) && data->objects[i].id != id)
        {
            compare_update_t(&data->objects[i], ray);
            if (ray->t < min_dist)
            {
                tmp_obj = &data->objects[i];
                min_dist = tmp_obj->t;
            }
            //return (true);
        }
        else if (data->objects[i].type == cone && \
        hit_cone(&data->objects[i], ray) && data->objects[i].id != id)
        {
            compare_update_t(&data->objects[i], ray);
            if (ray->t < min_dist)
            {
                tmp_obj = &data->objects[i];
                min_dist = tmp_obj->t;
            }
            //return (true);
        }
        i++;
    }
    if (ray->t > 0)
        return (true);
    return (false);
}
bool    hard_shadow(t_data *data, t_object *object, t_vec hit_point, \
bool inside)
{
    t_ray   shadow_ray;
    float   distance;
    // shadow_ray = malloc(sizeof(t_ray));
    shadow_ray.dir = unit_vector(sub(data->light.vec, hit_point));
    shadow_ray.orig = hit_point;
    distance = vec_len(sub(data->light.vec, hit_point));
    if (check_obj(data, &shadow_ray, object->id) && !inside)
    {
        t_vec hit_object_point = calc_hitpoint(shadow_ray,shadow_ray.t);
        float dis_form_hitobject = vec_len(sub(data->light.vec,hit_object_point));
        if (distance >= dis_form_hitobject)
            return (true);
        else
            return (false);
    }
    return (false);
}

t_vec   add_shading(t_data *data, t_object *object, t_vec hit_point, \
t_vec surf_norm)
{
    t_vec   col;
    float   diffuse;
    diffuse = calc_diffuse(data->light.vec, surf_norm, hit_point, \
    data->light.brightness);
    col = mult_fact(object->color, diffuse);
    col = add(col, calc_ambient(data, object));
    col.x = clamp(col.x, 0.0, 1.0);
    col.y = clamp(col.y, 0.0, 1.0);
    col.z = clamp(col.z, 0.0, 1.0);
    return (col);
}
t_vec   ray_color(t_ray ray, float t, t_object *object, t_data *data)
{
    t_vec   hit_point;
    t_vec   surf_norm;
    hit_point = calc_hitpoint(ray, t);
    if (object->type == plane)
        surf_norm = norm_plane(ray, object);
    else if (object->type == cylinder)
        surf_norm = norm_cylinder(ray, object, hit_point);
    else if (object->type == sphere)
        surf_norm = norm_sphere(&ray, object, hit_point);
    else
        surf_norm = norm_cone(ray, object, hit_point);
    if (hard_shadow(data, object, hit_point, ray.inside))
        return (add(set_vec(0.0f, 0.0f, 0.0f), calc_ambient(data, object)));
    return (add_shading(data, object, hit_point, surf_norm));
}



// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   color.c                                            :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: sven <sven@student.42.fr>                    +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2023/10/10 10:19:24 by yizhang       #+#    #+#                 */
// /*   Updated: 2024/01/31 16:53:58 by svan-has      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../minirt.h"
// bool    check_obj(t_data *data, t_ray *ray, t_object *temp, int id)
// {
//     int i;
//     i = 0;
//     ray->t = -1;
//     while (i < data->object_num)
//     {
//         if (data->objects[i].type == sphere && \
//         hit_sphere(&data->objects[i], ray) && data->objects[i].id != id)
//         {
//             // compare_update_t(&data->objects[i], ray);
//             temp = &data->objects[i];
//             return (true);
//         }
//         else if (data->objects[i].type == plane && \
//         hit_plane2(&data->objects[i], ray, data) && data->objects[i].id != id)
//         {
//             // compare_update_t(&data->objects[i], ray);
//             temp = &data->objects[i];
//             return (true);
//         }
//         else if (data->objects[i].type == cylinder && \
//         hit_cylinder(&data->objects[i], ray) && data->objects[i].id != id)
//         {
//             // compare_update_t(&data->objects[i], ray);
//             temp = &data->objects[i];
//             return (true);
//         }
//         else if (data->objects[i].type == cone && \
//         hit_cone(&data->objects[i], ray) && data->objects[i].id != id)
//         {
//             // compare_update_t(&data->objects[i], ray);
//             temp = &data->objects[i];
//             return (true);
//         }
//         i++;
//     }
//     // if (ray->t > 0)
//     //     return (true);
//     return (false);
// }

// t_object	*get_closest_obj(t_data *data, t_ray *ray)
// {
// 	float	min_dist;
// 	t_object	*closest_obj;
// 	t_object	tmp_hit;
//     int     i;

// 	closest_obj = NULL;
// 	min_dist = INFINITY;
//     i = 0;
// 	while (i < data->object_num)
// 	{
// 		if (check_obj(data, ray, &tmp_hit, data->objects[i].id))
// 		{
// 			if (tmp_hit.t < min_dist)
// 			{
// 				closest_obj = &data->objects[i];
// 				min_dist = tmp_hit.t;
// 			}
// 		}
// 		i++;
// 	}
// 	// if (closest_obj)
// 	// 	hit->color = color_obj(closest_obj, hit);
// 	return (closest_obj);
// }
    
// bool    hard_shadow(t_data *data, t_vec hit_point)
// {
//     t_ray   shadow_ray;
//     float   distance;
//     // shadow_ray = malloc(sizeof(t_ray));
//     shadow_ray.dir = unit_vector(sub(data->light.vec, hit_point));
//     shadow_ray.orig = hit_point;
//     distance = vec_len(sub(data->light.vec, hit_point));
//     t_object *closest = get_closest_obj(data, &shadow_ray);
//     if (closest)
//     {
//         t_vec hit_object_point = calc_hitpoint(shadow_ray,shadow_ray.t);
//         float dis_form_hitobject = vec_len(sub(data->light.vec,hit_object_point));
//         if (distance >= dis_form_hitobject)
//             return (true);
//         else
//             return (false);
//     }
//     // if (check_obj(data, &shadow_ray, object->id) && !inside)
//     // {
//     //     t_vec hit_object_point = calc_hitpoint(shadow_ray,shadow_ray.t);
//     //     float dis_form_hitobject = vec_len(sub(data->light.vec,hit_object_point));
//     //     if (distance >= dis_form_hitobject)
//     //         return (true);
//     //     else
//     //         return (false);
//     // }
//     return (false);
// }

// t_vec   add_shading(t_data *data, t_object *object, t_vec hit_point, \
// t_vec surf_norm)
// {
//     t_vec   col;
//     float   diffuse;
//     diffuse = calc_diffuse(data->light.vec, surf_norm, hit_point, \
//     data->light.brightness);
//     col = mult_fact(object->color, diffuse);
//     col = add(col, calc_ambient(data, object));
//     col.x = clamp(col.x, 0.0, 1.0);
//     col.y = clamp(col.y, 0.0, 1.0);
//     col.z = clamp(col.z, 0.0, 1.0);
//     return (col);
// }
// t_vec   ray_color(t_ray ray, float t, t_object *object, t_data *data)
// {
//     t_vec   hit_point;
//     t_vec   surf_norm;
//     hit_point = calc_hitpoint(ray, t);
//     if (object->type == plane)
//         surf_norm = norm_plane(ray, object);
//     else if (object->type == cylinder)
//         surf_norm = norm_cylinder(ray, object, hit_point);
//     else if (object->type == sphere)
//         surf_norm = norm_sphere(&ray, object, hit_point);
//     else
//         surf_norm = norm_cone(ray, object, hit_point);
//     if (hard_shadow(data, hit_point))
//         return (add(set_vec(0.0f, 0.0f, 0.0f), calc_ambient(data, object)));
//     return (add_shading(data, object, hit_point, surf_norm));
// }