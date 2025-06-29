/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:01:57 by niperez           #+#    #+#             */
/*   Updated: 2025/06/29 12:27:23 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	take_min_pos(double t1, double t2)
{
	if (t1 < EPS && t2 < EPS)
		return (-1);
	if (t1 < EPS && t2 > EPS)
		return (t2);
	if (t1 > EPS && t2 < EPS)
		return (t1);
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

static double	inter_sphere(t_ray *ray, t_obj *obj)
{
	t_vect		oc;
	t_equation	eq;
	double		t1;
	double		t2;

	oc = vect_sub(ray->point, obj->point);
	eq.a = prod_dot(ray->dir, ray->dir);
	eq.b = 2 * prod_dot(oc, ray->dir);
	eq.c = prod_dot(oc, oc) - (obj->diam / 2) * (obj->diam / 2);
	eq.delta = eq.b * eq.b - 4 * eq.a * eq.c;
	if (eq.delta < EPS)
		return (-1);
	t1 = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
	t2 = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
	return (take_min_pos(t1, t2));
}

t_inter	sphere_normal(t_inter hold, t_obj *obj, t_ray *ray)
{
	t_inter	inter;

	inter.dist = inter_sphere(ray, obj);
	if (inter.dist > EPS && (hold.dist < 0 || inter.dist < hold.dist))
	{
		inter.color = obj->color;
		inter.point = vect_add(ray->point, scal_mult(inter.dist, ray->dir));
		inter.norm = get_normalized(vect_sub(inter.point, obj->point));
		return (inter);
	}
	return (hold);
}
