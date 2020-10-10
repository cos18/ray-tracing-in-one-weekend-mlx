/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:33:55 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/10 15:53:50 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_sphere		*init_sphere(t_vec *center, double radius, t_vec *color)
{
	t_sphere	*result;

	result = (t_sphere *)malloc(sizeof(t_sphere));
	result->center = center;
	result->radius = radius;
	result->color = color;
	return (result);
}

void			free_sphere(t_sphere *s)
{
	free(s->center);
	free(s->color);
	free(s);
}

double			hit_sphere(t_sphere *s, t_ray *r)
{
	t_vec		*oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, s->center);
	a = vec_length_squared(r->dir);
	half_b = vec_dot(oc, r->dir);
	c = vec_length_squared(oc) - s->radius * s->radius;
	free(oc);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-half_b - sqrt(discriminant)) / a);
}

int				cal_ray_color(t_ray *r, t_sphere *s, double t)
{
	t_vec		*at;
	t_vec		*n;
	t_vec		*c;
	t_vec		*color;
	int			trgb;

	at = ray_at(r, t);
	n = vec_unit_apply(vec_sub(at, s->center));
	c = vec_create(1, 1, 1);
	color = vec_mul_const(vec_add_apply(n, c), 0.5 * 255.0);
	trgb = create_trgb(0, color);
	free(at);
	free(n);
	free(c);
	free(color);
	return (trgb);
}

void			draw_sphere(t_img_data *data, t_sky_info *info, t_sphere *s)
{
	t_sky		*my_sky;
	t_ray		*r;
	int			x;
	int			y;
	double		t;

	my_sky = init_sky(info, vec_create(0, 0, 0));
	my_sky->data = data;
	y = data->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < data->width)
		{
			r = cal_sky_ray(x, y, my_sky);
			t = hit_sphere(s, r);
			if (t > 0.0)
				data->img[x][y] = cal_ray_color(r, s, t);
			ray_free(r, FALSE);
		}
	}
	free_sky(my_sky, TRUE);
}
