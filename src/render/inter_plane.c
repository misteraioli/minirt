/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:59:13 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 15:39:08 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	inter_plane(t_ray *ray, t_obj *obj)
{
	double	a;
	double	b;

	a = prod_dot(vect_sub(ray->point, obj->point), obj->dir);
	b = prod_dot(ray->dir, obj->dir);
	if (fabs(b) < EPS)
		return (-1);
	return (-a / b);
}

t_inter	plane_normal(t_inter hold, t_obj *obj, t_ray *ray)
{
	t_inter	inter;

	inter.dist = inter_plane(ray, obj);
	if (inter.dist > EPS && (hold.dist < 0 || inter.dist < hold.dist))
	{
		inter.color = obj->color;
		inter.point = vect_add(ray->point, scal_mult(inter.dist, ray->dir));
		inter.norm = obj->dir;
		return (inter);
	}
	return (hold);
}
