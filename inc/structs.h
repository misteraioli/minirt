/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:55:53 by niperez           #+#    #+#             */
/*   Updated: 2025/06/23 17:26:03 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vect;

typedef struct s_cam
{
	t_vect	point;
	t_vect	dir;
	double	fov;
	int		count;

	t_vect	up;
	t_vect	right;
	double	height;
	double	width;
}	t_cam;

typedef struct s_amb
{
	double	ratio;
	t_vect	color;
	int		count;
}	t_amb;

typedef struct s_light
{
	t_vect	point;
	double	ratio;
	t_vect	color;
	int		count;
}	t_light;

typedef struct s_objs
{
	int				type;
	t_vect			point;
	t_vect			dir;
	double			diam;
	double			height;
	t_vect			color;
	t_vect			norm;
	struct s_objs	*next;
}	t_objs;

typedef struct s_img
{
	void	*ptr;
	char	*pixels_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_scene
{
	t_cam	cam;
	t_amb	amb;
	t_light	light;
	t_objs	*objs;

	void	*mlx;
	void	*mlx_window;
	t_img	img;
}	t_scene;

typedef struct s_ray
{
	t_vect	point;
	t_vect	dir;
	t_vect	color;
}	t_ray;

typedef struct s_inter
{
	double	t;
	t_vect	color;
	t_vect	hit;
	t_vect	norm;
}	t_inter;

typedef struct s_sphere
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	t1;
	double	t2;
	t_vect	oc;
}	t_sphere;

typedef struct s_cylinder
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	t1;
	double	t2;
	double	delta;
	double	y0;
	double	y1;
	t_vect	oc;
	t_vect	normal;
}	t_cylinder;

#endif
