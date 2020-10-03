/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:59 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/03 16:19:03 by sunpark          ###   ########.fr       */
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

typedef struct	s_mlx_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_data;

typedef struct	s_img_data {
	int			**img;
	int			width;
	int			height;
}				t_img_data;


typedef struct	s_vec {
	double		x;
	double		y;
	double		z;
}				t_vec;

int				create_trgb(int t, t_vec *color);
int				get_t(int trgb);
t_vec			*get_color(int trgb);

t_img_data		*create_img_data(int width, int height);
void			free_img_data(t_img_data *data);

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data);
int				mlx_key_handle(int keycode, t_vars *vars);
void			mlx_show(t_img_data *data);

# define BMP_HEADER_SIZE 122
void			save_bmp(t_img_data *data, char	*filename);

void			draw_gradaition(t_img_data *data);
void			draw_vertical_line(t_img_data *data, int x);
void			draw_horizontal_line(t_img_data *data, int y);

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