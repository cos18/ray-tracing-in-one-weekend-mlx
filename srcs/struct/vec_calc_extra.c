/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:29:30 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/19 16:35:56 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

// Need to delete this function before final submit

void		vec_print(t_vec *a)
{
	printf("%lf %lf %lf\n", a->x, a->y, a->z);
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
