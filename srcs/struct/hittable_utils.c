/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:35:38 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/14 05:33:42 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable		*hittable_create(void *obj, int obj_num)
{
	t_hittable	*result;

	result = (t_hittable *)malloc(sizeof(t_hittable));
	result->obj = obj;
	result->obj_num = obj_num;
	if (obj_num == OBJ_SPHERE)
		result->hit = &sphere_hit;
	return (result);
}

void			free_hittable(t_hittable *h)
{
	if (h->obj_num == OBJ_SPHERE)
		free_sphere(h->obj);
	free(h);
}
