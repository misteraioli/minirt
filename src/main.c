/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:54:36 by niperez           #+#    #+#             */
/*   Updated: 2025/06/09 19:32:20 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_err(t_scene sc, char *err)
{
	printf("Error : %s\n", err);
	if (sc.objs)
	exit(1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_scene	*sc;

	if (check_args(argc, argv))
		return(printf("wrong args : Please try enter filename.rt"), 1);
	sc = alloc_scene();
	if (!sc)
		return(printf("allocation scene"), 1);
	fd = open(argv[1], O_RDONLY);
	parse(sc, fd);
	//ft_render(sc);
	//ft_collect(&g_root, g_root);
	return (0);
}
