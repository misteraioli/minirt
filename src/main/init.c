/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:27:53 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 17:17:33 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_camera(t_cam *cam)
{
	double	screen_ratio;
	double	theta;

	screen_ratio = (double)WIDTH / (double)HEIGHT;
	theta = cam->fov * M_PI / 180.0;
	cam->height = tan(theta / 2);
	cam->width = cam->height * screen_ratio;
	cam->dir = get_normalized(cam->dir);
	if (fabs(prod_dot(cam->dir, set_vect(0.0, 0.0, 1.0))) > 1 - EPS)
	{
		if (cam->dir.z > 0)
			cam->right = get_normalized(prod_cross(cam->dir,
						set_vect(0.0, -1.0, 0.0)));
		else
			cam->right = get_normalized(prod_cross(cam->dir,
						set_vect(0.0, 1.0, 0.0)));
	}
	else
		cam->right = get_normalized(prod_cross(cam->dir,
					set_vect(0.0, 0.0, 1.0)));
	cam->up = get_normalized(prod_cross(cam->right, cam->dir));
}

static int	init_mlx(t_scene *sc)
{
	sc->mlx = mlx_init();
	if (sc->mlx == NULL)
		return (1);
	sc->mlx_window = mlx_new_window(sc->mlx, WIDTH, HEIGHT, "miniRT");
	if (sc->mlx_window == NULL)
	{
		mlx_destroy_display(sc->mlx);
		free(sc->mlx);
		return (1);
	}
	sc->img.ptr = mlx_new_image(sc->mlx, WIDTH, HEIGHT);
	if (sc->img.ptr == NULL)
	{
		mlx_destroy_window(sc->mlx, sc->mlx_window);
		mlx_destroy_display(sc->mlx);
		free(sc->mlx);
		return (1);
	}
	sc->img.pixels_ptr = mlx_get_data_addr(sc->img.ptr, &sc->img.bpp,
			&sc->img.size_line, &sc->img.endian);
	return (0);
}

static int	close_handler(t_scene *sc)
{
	mlx_destroy_image(sc->mlx, sc->img.ptr);
	mlx_destroy_window(sc->mlx, sc->mlx_window);
	mlx_destroy_display(sc->mlx);
	free(sc->mlx);
	free_scene(sc);
	exit(0);
}

static int	key_handler(int keysym, t_scene *sc)
{
	if (keysym == XK_Escape)
		close_handler(sc);
	return (0);
}

void	init(t_scene *sc)
{
	init_camera(&sc->cam);
	if (init_mlx(sc))
	{
		printf("Error : Failed to initialize image\n");
		free_scene(sc);
		exit(1);
	}
	mlx_hook(sc->mlx_window, KeyPress, KeyPressMask,
		key_handler, sc);
	mlx_hook(sc->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, sc);
}
