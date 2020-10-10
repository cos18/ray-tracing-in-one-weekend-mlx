/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:57:03 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/10 16:05:05 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hit_set_normal(t_hit_record *record, t_ray *r)
{
	record->is_front_face = (vec_dot(r->dir, record->normal) < 0) ?
								TRUE : FALSE;
	if (record->is_front_face == FALSE)
		vec_mul_const_apply(record->normal, -1);
}
