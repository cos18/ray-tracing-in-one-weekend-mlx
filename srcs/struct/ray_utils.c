/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:07:33 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/17 16:34:52 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		*ray_create(t_vec *origin, t_vec *direction)
{
	t_ray	*result;

	result = (t_ray *)malloc(sizeof(t_ray));
	result->orig = origin;
	result->dir = direction;
	return (result);
}

t_vec		*ray_at(t_ray *ray, double t)
{
	t_vec	*result;
	t_vec	*tmp_vec;

	tmp_vec = vec_mul_const(ray->dir, t);
	result = vec_add(tmp_vec, ray->orig);
	free(tmp_vec);
	return (result);
}

void		ray_free(t_ray *ray, int is_orig_free)
{
	if (ray == NULL)
		return ;
	if (is_orig_free && ray->orig != NULL)
		free(ray->orig);
	free(ray->dir);
	free(ray);
}
