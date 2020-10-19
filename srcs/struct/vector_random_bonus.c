/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_random_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:52:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/19 16:06:18 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec		*vec_random_range(double min, double max)
{
	return (vec_create(random_double_range(min, max),
						random_double_range(min, max),
						random_double_range(min, max)));
}

t_vec		*vec_random_in_unit_sphere(void)
{
	t_vec	*result;

	while (TRUE)
	{
		result = vec_random_range(-1, 1);
		if (vec_length_squared(result) >= 1)
		{
			free(result);
			continue ;
		}
		return (result);
	}
}

t_vec		*vec_random_unit(void)
{
	double	a;
	double	z;
	double	r;

	a = random_double_range(0, 2 * MINI_PI);
	z = random_double_range(-1, 1);
	r = sqrt(1.0 - z * z);
	return (vec_create(r * cos(a), r * sin(a), z));
}

t_vec		*vec_random_in_hemisphere(t_vec *normal)
{
	t_vec	*in_unit;

	in_unit = vec_random_unit();
	if (vec_dot(in_unit, normal) > 0.0)
		return (in_unit);
	return (vec_mul_const_apply(in_unit, -1.0));
}
