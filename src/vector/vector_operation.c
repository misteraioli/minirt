/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:08:27 by niperez           #+#    #+#             */
/*   Updated: 2025/06/13 20:28:43 by niperez          ###   ########.fr       */
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

t_vect	scal_mult(t_vect v, double a)
{
	v.x *= a;
	v.y *= a;
	v.z *= a;
	return (v);
}

double	prod_dot(t_vect u, t_vect v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vect	prod_cross(t_vect u, t_vect v)
{
	t_vect	w;

	w.x = (u.y * v.z) - (u.z * v.y);
	w.y = (u.z * v.x) - (u.x * v.z);
	w.z = (u.x * v.y) - (u.y * v.x);
	return (w);
}
