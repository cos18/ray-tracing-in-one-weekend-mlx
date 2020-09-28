/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:15:13 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 16:16:52 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_length_squared(t_vec *a)
{
	return (pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2));
}

double	vec_length(t_vec *a)
{
	return sqrt(vec_length_squared(a));
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
