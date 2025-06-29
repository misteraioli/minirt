/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:55:47 by niperez           #+#    #+#             */
/*   Updated: 2025/06/29 12:40:34 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define PL 1
# define SP 2
# define CY 3

# define WIDTH 1500
# define HEIGHT 1000
# define EPS 0.000001

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "structs.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// main
void		parse(t_scene *sc, char **argv);
void		init(t_scene *sc);
void		render(t_scene *sc);

// parse
t_vect		parse_vect(t_scene *sc, char **tokens, char *s, int fd);
t_vect		parse_color(t_scene *sc, char **tokens, char *s, int fd);

void		parse_ambient(t_scene *sc, char **tokens, int fd);
void		parse_camera(t_scene *sc, char **tokens, int fd);
void		parse_light(t_scene *sc, char **tokens, int fd);

void		parse_sphere(t_scene *sc, char **tokens, int fd);
void		parse_plane(t_scene *sc, char **tokens, int fd);
void		parse_cylinder(t_scene *sc, char **tokens, int fd);

double		ft_atod(const char *str);
void		free_split(char **s);
void		free_scene(t_scene *sc);
void		ft_err(t_scene *sc, char **tokens, int fd, char *err);

// render
void		set_ray_color(t_ray *ray, t_scene *sc);

t_inter		plane_normal(t_inter hold, t_obj *obj, t_ray *ray);
t_inter		sphere_normal(t_inter hold, t_obj *obj, t_ray *ray);
t_inter		cylinder_normal(t_inter hold, t_obj *obj, t_ray *ray);
double		take_min_pos(double t1, double t2);

// vector
t_vect		set_vect(double x, double y, double z);

double		get_norm(t_vect	v);
t_vect		get_normalized(t_vect v);

double		prod_dot(t_vect u, t_vect v);
t_vect		prod_cross(t_vect u, t_vect v);

t_vect		vect_add(t_vect u, t_vect v);
t_vect		vect_sub(t_vect u, t_vect v);
t_vect		vect_mult(t_vect u, t_vect v);
t_vect		scal_mult(double a, t_vect v);
t_vect		vect_clamp(t_vect v, double min, double max);

#endif
