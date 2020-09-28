/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:59 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 16:25:25 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vec {
	double		x;
	double		y;
	double		z;
}				t_vec;

int				create_trgb(int t, t_vec *color);
int				get_t(int trgb);
t_vec			*get_color(int trgb);

void			draw_gradaition(t_data *data, int width, int height);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				mlx_key_handle(int keycode, t_vars *vars);

t_vec			*vec_create(double x, double y, double z);
t_vec			*vec_add(t_vec *a, t_vec *b);
t_vec			*vec_sub(t_vec *a, t_vec *b);
t_vec			*vec_mul_const(t_vec *a, double c);
t_vec			*vec_div_const(t_vec *a, double c);

double			vec_length_squared(t_vec *a);
double			vec_length(t_vec *a);
double			vec_dot(t_vec *a, t_vec *b);
t_vec			*vec_cross(t_vec *a, t_vec *b);
t_vec			*vec_unit(t_vec *a);

#endif