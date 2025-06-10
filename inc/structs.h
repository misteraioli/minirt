/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:55:53 by niperez           #+#    #+#             */
/*   Updated: 2025/06/08 19:44:03 by niperez          ###   ########.fr       */
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

typedef struct s_scene
{
	t_cam	cam;
	t_amb	amb;
	t_light	light;
	t_objs	*objs;
}	t_scene;

#endif
