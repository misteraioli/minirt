/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:55:53 by niperez           #+#    #+#             */
/*   Updated: 2025/06/29 12:15:01 by niperez          ###   ########.fr       */
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

typedef struct s_obj
{
	int				type;
	t_vect			point;
	t_vect			dir;
	double			diam;
	double			height;
	t_vect			color;
	t_vect			norm;
	struct s_obj	*next;
}	t_obj;

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
	t_obj	*objs;

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
	double	dist;
	t_vect	point;
	t_vect	norm;
	t_vect	color;
}	t_inter;

typedef struct s_equation
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_equation;

#endif
