/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:41:56 by niperez           #+#    #+#             */
/*   Updated: 2025/06/29 12:39:53 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	parse_vect(t_scene *sc, char **tokens, char *s, int fd)
{
	char	**params;
	t_vect	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
	{
		free_split(params);
		ft_err(sc, tokens, fd, "invalid coordinates");
	}
	cord = set_vect(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
	free_split(params);
	return (cord);
}

t_vect	parse_color(t_scene *sc, char **tokens, char *s, int fd)
{
	char	**params;
	t_vect	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
	{
		free_split(params);
		ft_err(sc, tokens, fd, "invalid color!");
	}
	cord = (t_vect){ft_atoi(params[0]), ft_atoi(params[1]), ft_atoi(params[2])};
	if (cord.x > 255 || cord.y > 255 || cord.z > 255)
	{
		free_split(params);
		ft_err(sc, tokens, fd, "invalid color");
	}
	if (cord.x < 0 || cord.y < 0 || cord.z < 0)
	{
		free_split(params);
		ft_err(sc, tokens, fd, "invalid color");
	}
	free_split(params);
	return (cord);
}