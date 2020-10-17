/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:40:57 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/17 15:42:36 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*vec_create(double x, double y, double z)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_vec		*vec_dup(t_vec *ori)
{
	return (vec_create(ori->x, ori->y, ori->z));
}
