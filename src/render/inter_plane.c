/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:59:13 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 13:16:25 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	inter_plane(t_ray *ray, t_obj *obj)
{
	t_vect	x;
	double	t;
	double	b;
	double	a;

	x = vect_sub(ray->point, obj->point);
	b = prod_dot(ray->dir, obj->dir);
	if (b < -EPS || b > EPS)
	{
		a = prod_dot(x, obj->dir);
		t = -a / b;
		if (t < EPS)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}

t_inter	plane_normal(t_inter hold, t_obj *obj, t_ray *ray)
{
	t_inter	inter;

	inter.dist = inter_plane(ray, obj);
	if (((hold.dist > inter.dist || hold.dist == -1) && inter.dist > EPS))
	{
		inter.color = obj->color;
		inter.point = vect_add(ray->point, scal_mult(inter.dist, ray->dir));
		inter.norm = obj->dir;
		if (prod_dot(ray->dir, inter.norm) > 0)
			inter.norm = scal_mult(-1, obj->dir);
		hold = inter;
	}
	return (hold);
}
