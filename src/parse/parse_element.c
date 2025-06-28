/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:58:35 by niperez           #+#    #+#             */
/*   Updated: 2025/06/28 12:59:26 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(t_scene *sc, char **tokens, int fd)
{
	if (!tokens || !tokens[1] || !tokens[2] || tokens[3])
		ft_err(sc, tokens, fd, "invalid ambiant!");
	if (sc->amb.count != 0)
		ft_err(sc, tokens, fd, "too many ambiant");
	sc->amb.count++;
	sc->amb.ratio = ft_atod(tokens[1]);
	if (sc->amb.ratio < 0 || sc->amb.ratio > 1)
		ft_err(sc, tokens, fd,
			"enter ambient lighting ratio in range [0.0,1.0]");
	sc->amb.color = parse_color(sc, tokens, tokens[2], fd);
}

void	parse_camera(t_scene *sc, char **tokens, int fd)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err(sc, tokens, fd, "invalid camera !");
	if (sc->cam.count != 0)
		ft_err(sc, tokens, fd, "too many camera");
	sc->cam.count++;
	sc->cam.point = parse_vect(sc, tokens, tokens[1], fd);
	sc->cam.dir = parse_vect(sc, tokens, tokens[2], fd);
	if (fabs(sc->cam.dir.x) > 1 || fabs(sc->cam.dir.y) > 1 || fabs(sc->cam.dir.z) > 1)
		ft_err(sc, tokens, fd, "invalid orientation camera");
	if (sc->cam.dir.x == 0 && sc->cam.dir.y == 0 && sc->cam.dir.z == 0)
		ft_err(sc, tokens, fd, "invalid orientation camera");
	sc->cam.dir = get_normalized(sc->cam.dir);
	sc->cam.fov = ft_atod(tokens[3]);
	if (sc->cam.fov < 0 || sc->cam.fov > 180)
		ft_err(sc, tokens, fd, "FOV  in range [0,180]");
}

void	parse_light(t_scene *sc, char **tokens, int fd)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err(sc, tokens, fd, "invalid light !");
	if (sc->light.count != 0)
		ft_err(sc, tokens, fd, "too many light");
	sc->light.count++;
	sc->light.point = parse_vect(sc, tokens, tokens[1], fd);
	sc->light.ratio = ft_atod(tokens[2]);
	if (sc->light.ratio < 0 || sc->light.ratio > 1)
		ft_err(sc, tokens, fd,
			"enter the light brightness ratio in range [0.0,1.0]");
	sc->light.color = parse_color(sc, tokens, tokens[3], fd);
}
