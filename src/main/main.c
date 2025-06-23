/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:54:36 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 17:12:37 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_args(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc != 2)
		return (1);
	i = ft_strlen(argv[1]);
	if (i < 4)
		return (1);
	if (argv[1][i - 3] != '.' || argv[1][i - 2] != 'r' || argv[1][i - 1] != 't')
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	sc;

	if (check_args(argc, argv))
		return (printf("wrong args : Please try enter <filename>.rt\n"), 1);
	parse(&sc, argv);
	init(&sc);
	render(&sc);
	mlx_loop(sc.mlx);
	return (0);
}
