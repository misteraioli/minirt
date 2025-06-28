/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:13:09 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 14:02:36 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	find_inter(t_ray *ray, t_obj *obj)
{
	t_inter	inter;

	inter.dist = -1;
	while (obj)
	{
		if (obj->type == SP)
			inter = sphere_normal(inter, obj, ray);
		if (obj->type == PL)
			inter = plane_normal(inter, obj, ray);
		if (obj->type == CY)
			inter = cylinder_normal(inter, obj, ray);
		obj = obj->next;
	}
	return (inter);
}

void	set_ray_color(t_ray *ray, t_scene *sc)
{
	t_inter	inter;
	t_vect	amb;

	inter = find_inter(ray, sc->objs);
	if (inter.dist < 0)
		ray->color = scal_mult(sc->amb.ratio, sc->amb.color);
	else
	{
		if (prod_dot(ray->dir, inter.norm) > 0)
			inter.norm = scal_mult(-1, inter.norm);
		amb = scal_mult(sc->amb.ratio / 255,
				vect_mult(inter.color, sc->amb.color));
		ray->color = calcul_color(sc, inter, amb);
	}
}
