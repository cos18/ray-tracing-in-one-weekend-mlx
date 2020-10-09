/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:48:41 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/09 20:07:59 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTURE_H
# define MINIRT_STRUCTURE_H

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

t_vec			*vec_add_apply(t_vec *a, t_vec *b);
t_vec			*vec_sub_apply(t_vec *a, t_vec *b);
t_vec			*vec_mul_const_apply(t_vec *a, double c);
t_vec			*vec_div_const_apply(t_vec *a, double c);
t_vec			*vec_unit_apply(t_vec *a);
void			vec_print(t_vec *a);

typedef struct	s_ray {
	t_vec		*orig;
	t_vec		*dir;
}				t_ray;

t_ray			*ray_create(t_vec *origin, t_vec *direction);
t_vec			*ray_at(t_ray *ray, double t);
void			ray_free(t_ray *ray, int is_orig_free);

#endif
