/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:58:35 by niperez           #+#    #+#             */
/*   Updated: 2025/06/09 18:15:31 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(t_scene *sc, char **tokens)
{
	if (!tokens || !tokens[1] || !tokens[2] || tokens[3])
		ft_err("invalid ambiant!");
	if (sc->amb.count != 0)
		ft_err("too many ambiant");
	sc->amb.count++;
	sc->amb.ratio = ft_atod(tokens[1]);
	if (sc->amb.ratio < 0 || sc->amb.ratio > 1)
		ft_err("enter ambient lighting ratio in range [0.0,1.0]");
	sc->amb.color = parse_color(tokens[2]);
}

void	parse_camera(t_scene *sc, char **tokens)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err("invalid camera !");
	if (sc->cam.count != 0)
		ft_err("too many camera");
	sc->cam.count++;
	sc->cam.point = parse_vect(tokens[1]);
	sc->cam.dir = parse_vect(tokens[2]);
	if (sc->cam.dir.x > 1 || sc->cam.dir.y > 1 || sc->cam.dir.z > 1)
		ft_err("invalid orientation camera");
	if (sc->cam.dir.x < -1 || sc->cam.dir.y < -1 || sc->cam.dir.z < -1)
		ft_err("invalid orientation camera");
	if (sc->cam.dir.x == 0 && sc->cam.dir.y == 0 && sc->cam.dir.z == 0)
		ft_err("invalid orientation camera");
	sc->cam.fov = ft_atod(tokens[3]);
	if (sc->cam.fov < 0 || sc->cam.fov > 180)
		ft_err("FOV  in range [0,180]");
}

void	parse_light(t_scene *sc, char **tokens)
{
	if (!tokens || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		ft_err("invalid light !");
	if (sc->light.count != 0)
		ft_err("too many light");
	sc->light.count++;
	sc->light.point = parse_vect(tokens[1]);
	sc->light.ratio = ft_atod(tokens[2]);
	if (sc->light.ratio < 0 || sc->light.ratio > 1)
		ft_err("enter the light brightness ratio in range [0.0,1.0]");
	sc->light.color = parse_color(tokens[3]);
}
