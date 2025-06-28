/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:58:41 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 18:25:37 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	take_cyl_point(t_ray *ray, t_obj *obj, double t1, double t2)
{
	t_vect	oc;
	double	y1;
	double	y2;

	oc = vect_sub(ray->point, obj->point);
	y1 = prod_dot(ray->dir, obj->dir) * t1 + prod_dot(oc, obj->dir);
	y2 = prod_dot(ray->dir, obj->dir) * t2 + prod_dot(oc, obj->dir);
	if ((y1 >= EPS && y1 <= obj->height) && (y2 >= EPS && y2 <= obj->height))
		return (take_min_positif(t1, t2));
	if ((y1 >= EPS && y1 <= obj->height) && (y2 < EPS || y2 > obj->height))
		return (take_min_positif(t1, -1));
	if ((y1 < EPS || y1 > obj->height) && (y2 >= EPS && y2 <= obj->height))
		return (take_min_positif(-1, t2));
	else
		return (-1);
}

static double	inter_cylinder(t_ray *ray, t_obj *obj)
{
	t_vect		oc;
	t_equation	eq;
	double		t1;
	double		t2;

	oc = vect_sub(ray->point, obj->point);
	eq.a = 1 - (prod_dot(ray->dir, obj->dir) * prod_dot(ray->dir, obj->dir));
	eq.b = 2 * (prod_dot(ray->dir, oc)
			- (prod_dot(ray->dir, obj->dir) * prod_dot(oc, obj->dir)));
	eq.c = prod_dot(oc, oc) - (prod_dot(oc, obj->dir) * prod_dot(oc, obj->dir))
		- (obj->diam * obj->diam / 4);
	eq.delta = eq.b * eq.b - 4 * eq.a * eq.c;
	if (eq.delta < EPS)
		return (-1);
	t1 = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
	t2 = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
	return (take_cyl_point(ray, obj, t1, t2));
}

t_inter	cylinder_normal(t_inter hold, t_obj *obj, t_ray *ray)
{
	t_inter	inter;
	double	m;

	inter.dist = inter_cylinder(ray, obj);
	if (inter.dist > EPS && (hold.dist < 0 || inter.dist < hold.dist))
	{
		inter.color = obj->color;
		inter.point = vect_add(ray->point, scal_mult(inter.dist, ray->dir));
		m = prod_dot(ray->dir, scal_mult(inter.dist, obj->dir))
			+ prod_dot(vect_sub(ray->point, obj->point), obj->dir);
		inter.norm = get_normalized(vect_sub(vect_sub(inter.point, obj->point),
					scal_mult(m, obj->dir)));
		return (inter);
	}
	return (hold);
}
