/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:14:57 by niperez           #+#    #+#             */
/*   Updated: 2025/06/08 17:45:50 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args(int argc, char **argv)
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
