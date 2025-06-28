/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:38:07 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 12:22:21 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	set_vect(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	get_norm(t_vect	v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vect	get_normalized(t_vect v)
{
	return (scal_mult(1.0 / sqrt(get_norm(v)), v));
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
