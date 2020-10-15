/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:15:13 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 16:45:06 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

double	vec_length_squared(t_vec *a)
{
	return (pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2));
}

double	vec_length(t_vec *a)
{
	return (sqrt(vec_length_squared(a)));
}

double	vec_dot(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec	*vec_cross(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->y * b->z - a->z * b->y;
	result->y = a->z * b->x - a->x * b->z;
	result->z = a->x * b->y - a->y * b->x;
	return (result);
}

t_vec	*vec_unit(t_vec *a)
{
	return (vec_div_const(a, vec_length(a)));
}

// Need to delete this function before final submit

void	vec_print(t_vec *a)
{
	printf("%lf %lf %lf\n", a->x, a->y, a->z);
}
