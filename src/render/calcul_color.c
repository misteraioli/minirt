/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:14:42 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 12:42:18 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	shade(t_scene *sc, t_inter inter, t_light *light)
{
	t_vect		hit_light;
	t_ray		sh_ray;
	t_inter		shadow;
	t_vect		hit_sh;

	hit_light = vect_sub(light->point, inter.point);
	sh_ray.point = inter.point;
	sh_ray.dir = get_normalized(hit_light);
	shadow = find_inter(&sh_ray, sc->objs);
	hit_sh = vect_sub(shadow.point, sh_ray.point);
	if (shadow.dist > EPS && (get_norm(hit_light) > get_norm(hit_sh)))
		return (1);
	return (0);
}

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

t_vect	calcul_color(t_scene *sc, t_inter inter, t_vect amb)
{
	t_light		light;
	t_vect		ret;
	t_vect		hit_light;
	double		d;

	ret = set_vect(0, 0, 0);
	light = sc->light;
	if (!light.count)
		return (amb);
	if (shade(sc, inter, &light))
		ret = add_color(ret, amb);
	else
	{
		hit_light = vect_sub(light.point, inter.point);
		d = prod_dot(get_normalized(hit_light), inter.norm);
		ret = add_color(ret, amb);
		if (d > 0)
			ret = add_color(ret,
					scal_mult(d * light.ratio / 255,
						vect_mult(inter.color, light.color)));
	}
	return (ret);
}
