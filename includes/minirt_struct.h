/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:48:41 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/04 22:36:18 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTURE_H
# define MINIRT_STRUCTURE_H

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

typedef struct	s_ray {
	t_vec		*orig;
	t_vec		*dir;
}				t_ray;

t_ray			*ray_create(t_vec *origin, t_vec *direction);
t_vec			*ray_at(t_ray *ray, double t);
void			ray_free(t_ray	*ray);

#endif