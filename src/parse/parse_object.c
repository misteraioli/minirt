/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:00:22 by niperez           #+#    #+#             */
/*   Updated: 2025/06/08 19:46:37 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_scene *sc, char **tokens)
{
	t_objs	*obj;

	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err("invalid sphere");
	obj = alloc_obj(sc);
	obj->type = SP;
	obj->point = parse_vect(tokens[1]);
	obj->diam = ft_atod(tokens[2]);
	if (obj->diam <= 0)
		ft_err("invalid diameter sphere");
	obj->color = parse_color(tokens[3]);
}

void	parse_plane(t_scene *sc, char **tokens)
{
	t_objs	*obj;

	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err("invalid plane!");
	obj = alloc_obj(sc);
	obj->type = PL;
	obj->point = parse_vect(tokens[1]);
	obj->dir = parse_vect(tokens[2]);
	if (obj->dir.x > 1 || obj->dir.y > 1 || obj->dir.z > 1)
		ft_err("invalid orientation plane");
	if (obj->dir.x < -1 || obj->dir.y < -1 || obj->dir.z < -1)
		ft_err("invalid orientation plane");
	obj->color = parse_color(tokens[3]);
}

void	parse_cylinder(t_scene *sc, char **tokens)
{
	t_objs	*obj;

	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || !tokens[4]
		|| !tokens[5] || tokens[6])
		ft_err("invalid cylinder");
	obj = alloc_obj(sc);
	obj->type = CY;
	obj->point = parse_vect(tokens[1]);
	obj->dir = parse_vect(tokens[2]);
	if (obj->dir.x > 1 || obj->dir.y > 1 || obj->dir.z > 1)
		ft_err("invalid orientation cylinder");
	if (obj->dir.x < -1 || obj->dir.y < -1 || obj->dir.z < -1)
		ft_err("invalid orientation cylinder");
	obj->diam = ft_atod(tokens[3]);
	obj->height = ft_atod(tokens[4]);
	if (obj->diam <= 0 || obj->height <= 0)
		ft_err("invalid diameter cy");
	obj->color = parse_color(tokens[5]);
}
