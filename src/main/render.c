/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:14:30 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 16:12:34 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_ray(t_ray *ray, t_cam cam, double x, double y)
{
	double	u;
	double	v;

	ray->point = cam.point;
	u = (2.0 * x / (WIDTH - 1.0)) - 1.0;
	v = 1.0 - (2.0 * y / (HEIGHT - 1.0));
	ray->dir = get_normalized(
			vect_add(cam.dir,
				vect_add(scal_mult(cam.right, u * cam.width),
					scal_mult(cam.up, v * cam.height))));
}

static int	create_rgb(t_vect color)
{
	int	r;
	int	g;
	int	b;

	r = (int)color.x;
	g = (int)color.y;
	b = (int)color.z;
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels_ptr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	handle_pixel(t_scene *sc, int x, int y)
{
	t_ray	ray;

	init_ray(&ray, sc->cam, x, y);
	set_ray_color(&ray, sc);
	my_mlx_pixel_put(&sc->img, x, y, create_rgb(ray.color));
}

void	render(t_scene *sc)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(sc, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(sc->mlx, sc->mlx_window, sc->img.ptr, 0, 0);
}
