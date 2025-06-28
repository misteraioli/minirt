/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:00:22 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 13:09:48 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_obj	*alloc_obj(t_scene *sc)
{
	t_obj	*new_obj;

	new_obj = malloc(sizeof(t_obj));
	if (!new_obj)
		return (NULL);
	new_obj->next = sc->objs;
	sc->objs = new_obj;
	return (new_obj);
}

void	parse_sphere(t_scene *sc, char **tokens, int fd)
{
	t_obj	*obj;

	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err(sc, tokens, fd, "invalid sphere");
	obj = alloc_obj(sc);
	obj->type = SP;
	obj->point = parse_vect(sc, tokens, tokens[1], fd);
	obj->diam = ft_atod(tokens[2]);
	if (obj->diam <= 0)
		ft_err(sc, tokens, fd, "invalid diameter sphere");
	obj->color = parse_color(sc, tokens, tokens[3], fd);
}

void	parse_plane(t_scene *sc, char **tokens, int fd)
{
	t_obj	*obj;

	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err(sc, tokens, fd, "invalid plane!");
	obj = alloc_obj(sc);
	obj->type = PL;
	obj->point = parse_vect(sc, tokens, tokens[1], fd);
	obj->dir = parse_vect(sc, tokens, tokens[2], fd);
	if (fabs(obj->dir.x) > 1 || fabs(obj->dir.y) > 1 || fabs(obj->dir.z) > 1)
		ft_err(sc, tokens, fd, "invalid orientation plane");
	if (obj->dir.x == 0 && obj->dir.y == 0 && obj->dir.z == 0)
		ft_err(sc, tokens, fd, "invalid orientation plane");
	obj->dir = get_normalized(obj->dir);
	obj->color = parse_color(sc, tokens, tokens[3], fd);
}

void	parse_cylinder(t_scene *sc, char **tokens, int fd)
{
	t_obj	*obj;

	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || !tokens[4]
		|| !tokens[5] || tokens[6])
		ft_err(sc, tokens, fd, "invalid cylinder");
	obj = alloc_obj(sc);
	obj->type = CY;
	obj->point = parse_vect(sc, tokens, tokens[1], fd);
	obj->dir = parse_vect(sc, tokens, tokens[2], fd);
	if (fabs(obj->dir.x) > 1 || fabs(obj->dir.y) > 1 || fabs(obj->dir.z) > 1)
		ft_err(sc, tokens, fd, "invalid orientation cylinder");
	if (obj->dir.x == 0 && obj->dir.y == 0 && obj->dir.z == 0)
		ft_err(sc, tokens, fd, "invalid orientation cylinder");
	obj->dir = get_normalized(obj->dir);
	obj->diam = ft_atod(tokens[3]);
	obj->height = ft_atod(tokens[4]);
	if (obj->diam <= 0 || obj->height <= 0)
		ft_err(sc, tokens, fd, "invalid diameter cy");
	obj->color = parse_color(sc, tokens, tokens[5], fd);
}
