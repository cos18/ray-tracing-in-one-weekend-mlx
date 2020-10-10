/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:49:41 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/10 16:05:37 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int			check_sphere_hitrange(t_sphere *s, t_ray *r, t_sphere_hit_info *info, t_hit_record *rec)
{
	int		is_big_t;
	double	t;

	is_big_t = -1;
	while ((++is_big_t) < 2)
	{
		t = (-info->half_b + info->root_d * (is_big_t ? (1) : (-1))) / info->a;
		if (info->t_min < t && t < info->t_max)
		{
			rec->t = t;
			rec->p = ray_at(r, t);
			rec->normal = vec_div_const_apply(vec_sub(rec->p, s->center), s->radius);
			hit_set_normal(rec, r);
			return (TRUE);
		}
	}
	return (FALSE);
}

int			sphere_hit(t_sphere *s, t_ray *r, t_sphere_hit_info *info, t_hit_record *rec)
{
	t_vec	*oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec_sub(r->orig, s->center);
	a = vec_length_squared(r->dir);
	half_b = vec_dot(oc, r->dir);
	c = vec_length_squared(oc) - s->radius * s->radius;
	free(oc);
	discriminant = half_b * half_b - a * c;
	if (discriminant <= 0)
		return (FALSE);
	info->a = a;
	info->half_b = half_b;
	info->root_d = sqrt(discriminant);
	return (check_sphere_hitrange(s, r, info, rec));
}
