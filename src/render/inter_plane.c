/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:59:13 by niperez           #+#    #+#             */
/*   Updated: 2025/06/24 15:57:18 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	inter_plane(t_ray *ray, t_objs *obj)
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

t_inter	plane_normal(t_inter hold, t_objs *obj, t_ray *ray)
{
	t_inter	inter;

	inter.t = inter_plane(ray, obj);
	if (inter.t > 0 && (hold.t > inter.t || hold.t < 0))
	{
		inter.color = obj->color;
		inter.hit = vect_add(ray->point, scal_mult(ray->dir, inter.t));
		inter.norm = obj->dir;
		if (prod_dot(ray->dir, inter.norm) > 0)
			inter.norm = scal_mult(obj->dir, -1);
		hold = inter;
	}
	return (hold);
}
