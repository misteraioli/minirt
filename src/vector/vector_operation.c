/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:08:27 by niperez           #+#    #+#             */
/*   Updated: 2025/06/29 12:13:07 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	vect_add(t_vect u, t_vect v)
{
	t_vect	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vect	vect_sub(t_vect u, t_vect v)
{
	t_vect	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vect	vect_mult(t_vect u, t_vect v)
{
	t_vect	w;

	w.x = u.x * v.x;
	w.y = u.y * v.y;
	w.z = u.z * v.z;
	return (w);
}

t_vect	scal_mult(double a, t_vect v)
{
	v.x *= a;
	v.y *= a;
	v.z *= a;
	return (v);
}

t_vect	vect_clamp(t_vect v, double min, double max)
{
	if (v.x > max)
		v.x = max;
	if (v.y < min)
		v.y = min;
	else if (v.y > max)
		v.y = max;
	if (v.z < min)
		v.z = min;
	else if (v.z > max)
		v.z = max;
	return (v);
}
