/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:13:09 by niperez           #+#    #+#             */
/*   Updated: 2025/06/30 13:28:26 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_inter	find_inter(t_ray *ray, t_obj *obj)
{
	t_inter	inter;

	inter.dist = -1;
	while (obj)
	{
		if (obj->type == PL)
			inter = plane_normal(inter, obj, ray);
		if (obj->type == SP)
			inter = sphere_normal(inter, obj, ray);
		if (obj->type == CY)
			inter = cylinder_normal(inter, obj, ray);
		obj = obj->next;
	}
	return (inter);
}

static int	shade(t_obj *objs, t_inter inter, t_light light)
{
	t_ray	ray;
	t_vect	inter_to_light;
	t_inter	obstacle;

	ray.point = inter.point;
	inter_to_light = vect_sub(light.point, inter.point);
	ray.dir = get_normalized(inter_to_light);
	obstacle = find_inter(&ray, objs);
	return (obstacle.dist > EPS && obstacle.dist < get_norm(inter_to_light));
}

static t_vect	colorize(t_light light, t_obj *objs, t_inter inter, t_vect amb)
{
	double	cos;

	if (!light.count || shade(objs, inter, light))
		return (amb);
	cos = prod_dot(get_normalized(vect_sub(light.point, inter.point)),
			inter.norm);
	if (cos > 0)
		amb = vect_add(amb,
				scal_mult(cos * light.ratio / 255,
					vect_mult(inter.color, light.color)));
	return (vect_clamp(amb, 0, 255));
}

void	set_ray_color(t_ray *ray, t_scene *sc)
{
	t_inter	inter;
	t_vect	ambiant;

	inter = find_inter(ray, sc->objs);
	if (inter.dist < 0)
		ray->color = set_vect(0, 0, 0);
	else
	{
		if (prod_dot(ray->dir, inter.norm) > 0)
			inter.norm = scal_mult(-1, inter.norm);
		ambiant = scal_mult(sc->amb.ratio / 255,
				vect_mult(sc->amb.color, inter.color));
		ray->color = colorize(sc->light, sc->objs, inter, ambiant);
	}
}
