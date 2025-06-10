/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:38:07 by niperez           #+#    #+#             */
/*   Updated: 2025/06/08 20:24:46 by niperez          ###   ########.fr       */
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
	return (scal_mult(v, 1.0 / sqrt(get_norm(v))));
}
