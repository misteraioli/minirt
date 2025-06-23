/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:01:57 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 16:30:00 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	take_min(double x, double y)
{
	if (x > y)
		return (y);
	return (x);
}

static double	inter_sphere(t_ray *ray, t_objs *sp)
{
	t_sphere	sph;

	sph.oc = vect_sub(ray->point, sp->point);
	sph.a = prod_dot(ray->dir, ray->dir);
	sph.b = 2.0 * prod_dot(sph.oc, ray->dir);
	sph.c = prod_dot(sph.oc, sph.oc) - (sp->diam / 2.0) * (sp->diam / 2.0);
	sph.t = sph.b * sph.b - (4 * sph.a * sph.c);
	if (sph.t < EPS)
		return (-1);
	sph.t1 = (sph.b * (-1.0) - sqrt(sph.t)) / (2.0 * sph.a);
	sph.t2 = (sph.b * (-1.0) + sqrt(sph.t)) / (2.0 * sph.a);
	if (sph.t1 * sph.t2 > EPS)
	{
		if (sph.t1 > EPS)
			return (take_min(sph.t1, sph.t2));
		return (-1);
	}
	if (sph.t1 > EPS)
		return (sph.t1);
	return (sph.t2);
}

t_inter	sphere_normal(t_inter hold, t_objs *obj, t_ray *ray)
{
	t_inter	inter;

	inter.t = inter_sphere(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPS))
	{
		inter.color = obj->color;
		inter.hit = vect_add(ray->point, scal_mult(ray->dir, inter.t));
		inter.norm = get_normalized(vect_sub(inter.hit, obj->point));
		hold = inter;
	}
	return (hold);
}
