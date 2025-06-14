/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:14:01 by niperez           #+#    #+#             */
/*   Updated: 2025/06/09 18:09:28 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	parse_color(char *s)
{
	char	**params;
	t_vect	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
		ft_err("invalid color!");
	cord = (t_vect){ft_atoi(params[0]), ft_atoi(params[1]), ft_atoi(params[2])};
	if (cord.x > 255 || cord.y > 255 || cord.z > 255)
		ft_err("invalid color");
	if (cord.x < 0 || cord.y < 0 || cord.z < 0)
		ft_err("invalid color");
	free_split(params);
	return (cord);
}

t_vect	parse_vect(char *s)
{
	char	**params;
	t_vect	cord;

	params = ft_split(s, ',');
	if (!params || !params[1] || !params[2] || params[3])
		ft_err("invalid coordinates");
	cord = set_vect(ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2]));
	free_split(params);
	return (cord);
}

static void	parse_line(char *id, char **tokens, t_scene *sc)
{
	if (id[0] == 'C' && id[1] == '\0')
		parse_camera(sc, tokens);
	else if (id[0] == 'A' && id[1] == '\0')
		parse_ambient(sc, tokens);
	else if (id[0] == 'L' && id[1] == '\0')
		parse_light(sc, tokens);
	else if (id[0] == 's' && id[1] == 'p' && id[2] == '\0')
		parse_sphere(sc, tokens);
	else if (id[0] == 'p' && id[1] == 'l' && id[2] == '\0')
		parse_plane(sc, tokens);
	else if (id[0] == 'c' && id[1] == 'y' && id[2] == '\0')
		parse_cylinder(sc, tokens);
	else
		ft_err("invalid object type");
}

void	parse(t_scene *sc, int fd)
{
	char	**tokens;

	while (1)
	{
		tokens = ft_split(get_next_line(fd), ' ');

		if (tokens == NULL)
			break ;
		if (*tokens)
			parse_line(*tokens, tokens, sc);
		free_split(tokens);
	}
	close(fd);
}
