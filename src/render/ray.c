/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:13:09 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 16:51:15 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	find_inter(t_ray *ray, t_scene *sc)
{
	t_inter	hold;
	t_objs	*obj;

	hold.t = -1.0;
	obj = sc->objs;
	while (obj)
	{
		if (obj->type == SP)
			hold = sphere_normal(hold, obj, ray);
		if (obj->type == PL)
			hold = plane_normal(hold, obj, ray);
		if (obj->type == CY)
			hold = cylinder_normal(hold, obj, ray);
		obj = obj->next;
	}
	return (hold);
}

void	set_ray_color(t_ray *ray, t_scene *sc)
{
	t_inter	inter;
	t_vect	amb;

	inter = find_inter(ray, sc);
	if (inter.t > EPS)
	{
		amb = add_coef(inter.color, sc->amb.color, sc->amb.ratio);
		if (prod_dot(ray->dir, inter.norm) > 0)
			inter.norm = scal_mult(inter.norm, -1);
		ray->color = calcul_color(sc, inter, amb);
	}
	else
		ray->color = scal_mult(sc->amb.color, sc->amb.ratio);
}
