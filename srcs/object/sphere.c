/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:33:55 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/09 16:47:29 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int				hit_sphere(t_sphere *s, t_ray *r)
{
	t_vec		*oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, s->center);
	a = vec_dot(r->dir, r->dir);
	b = vec_dot(oc, r->dir) * 2.0;
	c = vec_dot(oc, oc) - s->radius * s->radius;
	free(oc);
	discriminant = b * b - 4 * a * c;
	return ((discriminant > 0) ? TRUE : FALSE);
}

void			draw_sphere(t_img_data *data, t_sky_info *info, t_sphere *s)
{
	t_vec		*origin;
	t_sky		*my_sky;
	t_ray		*r;
	int			x;
	int			y;

	origin = vec_create(0, 0, 0);
	my_sky = init_sky(info, origin);
	my_sky->data = data;
	y = data->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < data->width)
		{
			r = cal_sky_ray(x, y, my_sky, origin);
			if (hit_sphere(s, r))
				data->img[x][y] = create_trgb(0, s->color);
			ray_free(r, FALSE);
		}
	}
	free(origin);
	free_sky(my_sky);
}
