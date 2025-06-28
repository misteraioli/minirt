/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:01:57 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 14:57:33 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	take_min_positif(double t1, double t2)
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
	t_vect	oc;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	oc = vect_sub(ray->point, obj->point);
	a = prod_dot(ray->dir, ray->dir);
	b = 2 * prod_dot(oc, ray->dir);
	c = prod_dot(oc, oc) - (obj->diam / 2) * (obj->diam / 2);
	delta = b * b - (4 * a * c);
	if (delta < EPS)
		return (-1);
	t1 = ((-1) * b - sqrt(delta)) / (2 * a);
	t2 = ((-1) * b + sqrt(delta)) / (2 * a);
	return(take_min_positif(t1, t2));
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
		if (prod_dot(ray->dir, inter.norm) > 0)
			inter.norm = scal_mult(-1, inter.norm);
		return (inter);
	}
	return (hold);
}
