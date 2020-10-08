/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:35:13 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/08 19:39:52 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_sky		*init_sky(double viewport_width, double viewport_height,
						double focal_length, t_vec *origin)
{
	t_sky	*result;
	t_vec	*tmp;
	t_vec	*tmp2;
	t_vec	*tmp3;

	result = (t_sky *)malloc(sizeof(t_sky));
	result->horizontal = vec_create(viewport_width, 0, 0);
	result->vertical = vec_create(0, viewport_height, 0);
	vec_div_const_apply(result->horizontal, 2.0);
	vec_div_const_apply(result->vertical, 2.0);
	tmp = vec_add(result->horizontal, result->vertical);
	tmp2 = vec_create(0, 0, focal_length);
	tmp3 = vec_add(tmp, tmp2);
	result->lower_left_corner = vec_sub(origin, tmp3);
	free(tmp);
	free(tmp2);
	free(tmp3);
	vec_mul_const_apply(result->horizontal, 2.0);
	vec_mul_const_apply(result->vertical, 2.0);
	return (result);
}

int			cal_ray_color(int x, int y, t_sky *my_sky, t_vec *origin)
{
	t_ray	*r;
	t_vec	*tmp;
	t_vec	*tmp2;
	double	t;
	int		result;

	tmp = vec_mul_const(my_sky->horizontal,
							(double)x / (my_sky->data->width - 1));
	tmp2 = vec_mul_const(my_sky->vertical,
							(double)y / (my_sky->data->height - 1));
	vec_add_apply(tmp, tmp2);
	free(tmp2);
	vec_add_apply(tmp, my_sky->lower_left_corner);
	r = ray_create(origin, vec_sub_apply(tmp, origin));
	tmp = vec_unit(r->dir);
	t = 0.5 * (tmp->y + 1.0);
	free(tmp);
	tmp = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
	tmp2 = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
	vec_mul_const_apply(vec_add_apply(tmp, tmp2), 255);
	free(tmp2);
	result = create_trgb(0, tmp);
	free(tmp);
	ray_free(r, FALSE);
	return (result);
}

void		free_sky(t_sky *my_sky)
{
	free(my_sky->horizontal);
	free(my_sky->vertical);
	free(my_sky->lower_left_corner);
	free(my_sky);
}

void		draw_sky(t_img_data *data, double viewport_width,
						double viewport_height, double focal_length)
{
	t_vec	*origin;
	t_sky	*my_sky;
	int		x;
	int		y;

	origin = vec_create(0, 0, 0);
	my_sky = init_sky(viewport_width, viewport_height, focal_length, origin);
	my_sky->data = data;
	y = data->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < data->width)
			data->img[x][y] = cal_ray_color(x, y, my_sky, origin);
	}
	free(origin);
	free_sky(my_sky);
}
