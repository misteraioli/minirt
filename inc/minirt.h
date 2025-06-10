/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:55:47 by niperez           #+#    #+#             */
/*   Updated: 2025/06/08 20:11:42 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define SP 1
# define PL 2
# define CY 3

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "structs.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void		ft_err(char *err);
int			check_args(int ac, char **av);
t_scene		*alloc_scene(void);
t_objs		*alloc_obj(t_scene *sc);

//parse
void		parse(t_scene *sc, int fd);
t_vect		parse_vect(char *s);
t_vect		parse_color(char *s);

void		parse_camera(t_scene *sc, char **tokens);
void		parse_ambient(t_scene *sc, char **tokens);
void		parse_light(t_scene *sc, char **tokens);

void		parse_sphere(t_scene *sc, char **tokens);
void		parse_plane(t_scene *sc, char **tokens);
void		parse_cylinder(t_scene *sc, char **tokens);

//vector
t_vect		set_vect(double x, double y, double z);
double		get_norm(t_vect	v);
t_vect		get_normalized(t_vect v);

t_vect		vect_sub(t_vect u, t_vect v);
t_vect		vect_add(t_vect u, t_vect v);
t_vect		scal_mult(t_vect v, double a);
double		prod_dot(t_vect u, t_vect v);
t_vect		prod_cross(t_vect u, t_vect v);

//utils
void		free_split(char **s);
double		ft_atod(const char *str);

#endif
