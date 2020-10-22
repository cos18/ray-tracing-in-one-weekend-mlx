/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:29:30 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/23 08:28:52 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

// Need to delete this function before final submit

void		vec_print(t_vec *a)
{
	printf("%lf %lf %lf\n", a->x, a->y, a->z);
}

int			vec_is_parallel(t_vec *a, t_vec *b)
{
	double	dot;
	double	length;

	dot = vec_dot(a, b);
	dot = ((dot < 0) ? (-1 * dot) : dot);
	length = vec_length(a) * vec_length(b);
	return ((dot == length) ? TRUE : FALSE);
}

t_vec		*vec_cross_apply(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = vec_cross(a, b);
	a->x = result->x;
	a->y = result->y;
	a->z = result->z;
	free(result);
	return (a);
}

t_vec		*vec_cross_apply_tob(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = vec_cross(a, b);
	b->x = result->x;
	b->y = result->y;
	b->z = result->z;
	free(result);
	return (b);
}

t_vec		*vec_mul_each(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x * b->x;
	result->y = a->y * b->y;
	result->z = a->z * b->z;
	return (result);
}

t_vec		*vec_mul_each_apply(t_vec *a, t_vec *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
	return (a);
}
