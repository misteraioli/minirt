/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:58:41 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 16:30:06 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	pick_cy_inter(t_cylinder inf, t_ray *ray, t_objs *cy)
{
	inf.t1 = (-inf.b + sqrt(inf.delta)) / (2 * inf.a);
	inf.t2 = (-inf.b - sqrt(inf.delta)) / (2 * inf.a);
	if (inf.t1 < EPS)
		return (-1.0);
	if (inf.t1 > inf.t2)
		inf.t = inf.t2;
	else
		inf.t = inf.t1;
	inf.y0 = prod_dot(ray->dir, inf.normal) * inf.t2
		+ prod_dot(inf.oc, inf.normal);
	inf.y1 = prod_dot(ray->dir, inf.normal) * inf.t1
		+ prod_dot(inf.oc, inf.normal);
	if (inf.y0 >= EPS && inf.y0 <= cy->height)
		return (inf.t2);
	if (inf.y1 >= EPS && inf.y1 <= cy->height)
		return (inf.t1);
	return (-1.0);
}

static double	inter_cylinder(t_ray *r, t_objs *cy)
{
	t_cylinder	inf;
	double		t;

	inf.normal = get_normalized(cy->dir);
	inf.oc = vect_sub(r->point, cy->point);
	inf.a = prod_dot(r->dir, r->dir) - (prod_dot(r->dir, inf.normal)
			* prod_dot(r->dir, inf.normal));
	inf.b = 2 * (prod_dot(r->dir, inf.oc) - (prod_dot(r->dir, inf.normal)
				* prod_dot(inf.oc, inf.normal)));
	inf.c = prod_dot(inf.oc, inf.oc)
		- (prod_dot(inf.oc, inf.normal) * prod_dot(inf.oc, inf.normal))
		- (cy->diam / 2) * (cy->diam / 2);
	inf.delta = inf.b * inf.b - 4 * inf.a * inf.c;
	if (inf.delta < EPS)
		return (-1.0);
	t = pick_cy_inter(inf, r, cy);
	return (t);
}

t_inter	cylinder_normal(t_inter hold, t_objs *obj, t_ray *ray)
{
	t_inter	inter;
	double	m;
	t_vect	oc;

	inter.t = inter_cylinder(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPS))
	{
		inter.color = obj->color;
		inter.hit = vect_add(ray->point, scal_mult(ray->dir, inter.t));
		oc = get_normalized(obj->dir);
		m = prod_dot(ray->dir, scal_mult(oc, inter.t))
			+ prod_dot(vect_sub(ray->point, obj->point), oc);
		inter.norm = get_normalized(vect_sub(vect_sub(inter.hit, obj->point),
					scal_mult(oc, m)));
		hold = inter;
	}
	return (hold);
}
