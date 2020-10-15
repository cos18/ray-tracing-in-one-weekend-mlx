/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:34:23 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 10:43:59 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*vec_add_apply(t_vec *a, t_vec *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vec	*vec_sub_apply(t_vec *a, t_vec *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}

t_vec	*vec_mul_const_apply(t_vec *a, double c)
{
	a->x *= c;
	a->y *= c;
	a->z *= c;
	return (a);
}

t_vec	*vec_div_const_apply(t_vec *a, double c)
{
	a->x /= c;
	a->y /= c;
	a->z /= c;
	return (a);
}

t_vec	*vec_unit_apply(t_vec *a)
{
	return (vec_div_const_apply(a, vec_length(a)));
}
