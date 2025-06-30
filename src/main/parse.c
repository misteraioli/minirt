/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:14:01 by niperez           #+#    #+#             */
/*   Updated: 2025/06/30 13:27:50 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_scene(t_scene *sc)
{
	sc->amb.count = 0;
	sc->cam.count = 0;
	sc->light.count = 0;
	sc->objs = NULL;
}

static void	parse_line(char *id, char **tokens, int fd, t_scene *sc)
{
	if (id[0] == 'C' && id[1] == '\0')
		parse_camera(sc, tokens, fd);
	else if (id[0] == 'A' && id[1] == '\0')
		parse_ambient(sc, tokens, fd);
	else if (id[0] == 'L' && id[1] == '\0')
		parse_light(sc, tokens, fd);
	else if (id[0] == 'p' && id[1] == 'l' && id[2] == '\0')
		parse_plane(sc, tokens, fd);
	else if (id[0] == 's' && id[1] == 'p' && id[2] == '\0')
		parse_sphere(sc, tokens, fd);
	else if (id[0] == 'c' && id[1] == 'y' && id[2] == '\0')
		parse_cylinder(sc, tokens, fd);
	else if (id[0] == '\n')
		;
	else
		ft_err(sc, tokens, fd, "invalid object type");
}

void	parse(t_scene *sc, char **argv)
{
	int		fd;
	char	*line;
	char	**tokens;

	init_scene(sc);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		tokens = ft_split(line, ' ');
		free(line);
		if (tokens == NULL)
			break ;
		if (*tokens)
			parse_line(*tokens, tokens, fd, sc);
		free_split(tokens);
	}
	close(fd);
}
