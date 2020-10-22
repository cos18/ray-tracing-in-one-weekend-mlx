/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:31:29 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/23 08:28:26 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_material		*mat_lambertian_new(t_vec *color)
{
	t_material	*result;

	result = material_new(MAT_LAMBERTIAN, color);
	result->scatter = &lambertian_scatter;
	return (result);
}

int				lambertian_scatter(t_material *mat, t_ray *ray_in,
								t_hit_record *rec, t_material_info *info)
{
	t_vec		*scatter_direction;

	ray_in->dir->x = ray_in->dir->x;
	scatter_direction = vec_add_apply(vec_random_unit(), rec->normal);
	info->scattered = ray_create(vec_dup(rec->p), scatter_direction);
	info->attenuation = vec_dup(mat->color);
	return (TRUE);
}

t_material		*mat_metal_new(t_vec *color, double fuzz)
{
	t_material	*result;

	result = material_new(MAT_METAL, color);
	result->scatter = &metal_scatter;
	result->fuzz = ((fuzz < 1) ? fuzz : 1);
	return (result);
}

int				metal_scatter(t_material *mat, t_ray *ray_in, t_hit_record *rec,
						t_material_info *info)
{
	t_vec		*reflected;
	t_vec		*tmp;

	tmp = vec_unit(ray_in->dir);
	reflected = vec_reflect(tmp, rec->normal);
	free(tmp);
	tmp = vec_mul_const_apply(vec_random_in_unit_sphere(), mat->fuzz);
	info->scattered = ray_create(vec_dup(rec->p),
							vec_add_apply(reflected, tmp));
	free(tmp);
	info->attenuation = vec_dup(mat->color);
	return ((vec_dot(info->scattered->dir, rec->normal) > 0) ? TRUE : FALSE);
}
