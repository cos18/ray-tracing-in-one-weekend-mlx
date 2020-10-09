/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:01:03 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/09 16:08:50 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		*cal_sky_ray(int x, int y, t_sky *my_sky, t_vec *origin)
{
	t_ray	*r;
	t_vec	*tmp;
	t_vec	*tmp2;

	tmp = vec_mul_const(my_sky->horizontal,
							(double)x / (my_sky->data->width - 1));
	tmp2 = vec_mul_const(my_sky->vertical,
							(double)y / (my_sky->data->height - 1));
	vec_add_apply(tmp, tmp2);
	free(tmp2);
	vec_add_apply(tmp, my_sky->lower_left_corner);
	r = ray_create(origin, vec_sub_apply(tmp, origin));
	return (r);
}
