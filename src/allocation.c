/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:11:01 by niperez           #+#    #+#             */
/*   Updated: 2025/06/09 18:24:37 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*alloc_scene(void)
{
	t_scene	*sc;

	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	sc->amb.count = 0;
	sc->cam.count = 0;
	sc->light.count = 0;
	sc->objs = NULL;
	return (sc);
}

t_objs	*alloc_obj(t_scene *sc)
{
	t_objs	*new_obj;

	new_obj = malloc(sizeof(t_objs));
	if (!new_obj)
		return (NULL);
	new_obj->next = sc->objs;
	sc->objs = new_obj;
	return (new_obj);
}
