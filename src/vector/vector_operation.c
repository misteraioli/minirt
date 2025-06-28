/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:08:27 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 12:14:04 by niperez          ###   ########.fr       */
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
