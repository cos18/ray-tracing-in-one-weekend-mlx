/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:28:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/18 19:00:48 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*vec_add(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	return (result);
}

t_vec		*vec_sub(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	return (result);
}

t_vec		*vec_mul_const(t_vec *a, double c)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x * c;
	result->y = a->y * c;
	result->z = a->z * c;
	return (result);
}

t_vec		*vec_div_const(t_vec *a, double c)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x / c;
	result->y = a->y / c;
	result->z = a->z / c;
	return (result);
}

t_vec		*vec_reflect(t_vec *v, t_vec *n)
{
	t_vec	*result;
	t_vec	*tmp;

	tmp = vec_mul_const(n, 2 * vec_dot(v, n));
	result = vec_sub(v, tmp);
	free(tmp);
	return (result);
}
