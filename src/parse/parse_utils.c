/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:41:47 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 17:12:42 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_atod(const char *str)
{
	double	nb;
	int		signe;
	int		i;
	int		aux;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] != '.')
		return ((double)nb * signe);
	aux = 10;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		nb += (double)(str[i] - '0') / aux;
		aux *= 10;
	}
	return ((double)nb * signe);
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_scene(t_scene *sc)
{
	t_objs	*tmp;

	while (sc->objs)
	{
		tmp = sc->objs;
		sc->objs = sc->objs->next;
		free(tmp);
	}
}

void	ft_err(t_scene *sc, char **tokens, int fd, char *err)
{
	char	*line;

	printf("Error : %s\n", err);
	free_scene(sc);
	free_split(tokens);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit(1);
}
