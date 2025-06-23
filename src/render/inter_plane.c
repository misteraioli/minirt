/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:59:13 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 16:29:49 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	inter_plane(t_ray *ray, t_objs *pl)
{
	t_vect	x;
	t_vect	normal;
	double	t;
	double	b;
	double	a;

	normal = get_normalized(pl->dir);
	x = vect_sub(ray->point, pl->point);
	b = prod_dot(ray->dir, normal);
	if (b != 0)
	{
		a = prod_dot(x, normal);
		t = -a / b;
		if (t < EPS)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}

t_inter	plane_normal(t_inter hold, t_objs *obj, t_ray *ray)
{
	t_inter	inter;

	inter.t = inter_plane(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPS))
	{
		inter.color = obj->color;
		inter.hit = vect_add(ray->point, scal_mult(ray->dir, inter.t));
		inter.norm = obj->dir;
		if (prod_dot(ray->dir, inter.norm) > __DBL_EPSILON__)
			inter.norm = get_normalized(scal_mult(obj->dir, -1));
		hold = inter;
	}
	return (hold);
}
