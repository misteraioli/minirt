/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:14:42 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 20:12:48 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vect	add_color(t_vect col1, t_vect col2)
{
	t_vect	res;

	res = vect_add(col1, col2);
	if (res.x > 255)
		res.x = 255;
	if (res.y > 255)
		res.y = 255;
	if (res.z > 255)
		res.z = 255;
	return (res);
}

static int	shade(t_obj *objs, t_inter inter, t_light light)
{
	t_ray	ray;
	t_vect	inter_to_light;
	t_inter	obstacle;

	ray.point = inter.point;
	inter_to_light = vect_sub(light.point, inter.point);
	ray.dir = get_normalized(inter_to_light);
	obstacle = find_inter(&ray, objs);
	return (obstacle.dist > EPS
		&& obstacle.dist < sqrt(get_norm(inter_to_light)));
}

t_vect	calcul_color(t_light light, t_obj *objs, t_inter inter, t_vect amb)
{
	double	cos;

	if (!light.count || shade(objs, inter, light))
		return (amb);
	cos = prod_dot(get_normalized(vect_sub(light.point, inter.point)),
			inter.norm);
	if (cos > 0)
		amb = add_color(amb,
				scal_mult(cos * light.ratio / 255,
					vect_mult(inter.color, light.color)));
	return (amb);
}
