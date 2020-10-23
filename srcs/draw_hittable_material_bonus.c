/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable_material_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:55:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/23 13:31:15 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec				*get_sky_color_t(double t)
{
	t_vec			*target;
	t_vec			*tmp;

	tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
	target = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
	vec_add_apply(target, tmp);
	free(tmp);
	return (target);
}

t_vec				*get_recur_mat_color(t_list *lst, t_hitlst_info **info,
											int depth, int *is_free)
{
	t_material		*mat;
	t_material_info	mat_info;
	t_vec			*target;
	double			t;

	if (depth <= 0)
		return (vec_create(0, 0, 0));
	if (hitlst_hit(lst, *info))
	{
		mat = (*info)->rec->mat;
		if ((t = (*(mat->scatter))(mat, (*info)->ray, (*info)->rec, &mat_info)))
		{
			free_hitlst_info(*info, (*is_free)++);
			*info = hitlst_info_new(mat_info.scattered);
			target = vec_mul_each_apply(
	get_recur_mat_color(lst, info, depth - 1, is_free), mat_info.attenuation);
		}
		else
			target = vec_create(0, 0, 0);
		free_material_info(&mat_info, FALSE, !t);
		return (target);
	}
	t = 0.5 * ((vec_unit_apply((*info)->ray->dir))->y + 1.0);
	return (get_sky_color_t(t));
}

void				get_hittable_material_color(t_list *lst,
												t_hitlst_info **info,
												t_vec *color)
{
	t_vec			*target;
	int				is_free;

	is_free = FALSE;
	target = get_recur_mat_color(lst, info, REFLECT_DEPTH, &is_free);
	vec_add_apply(color, target);
	free(target);
	free_hitlst_info(*info, is_free);
}

void				draw_hittable_material(t_camera *cam, t_list *lst)
{
	int				x;
	int				y;
	int				locate;
	t_vec			*color;
	t_hitlst_info	*lst_info;

	y = cam->data->height;
	while ((--y) >= 0)
	{
		x = -1;
		while ((++x) < cam->data->width)
		{
			color = vec_create(0, 0, 0);
			locate = -1;
			while ((++locate) < ANTI_SAMPLES)
			{
				lst_info = get_hitlst_by_locate(x, y, cam);
				get_hittable_material_color(lst, &lst_info, color);
			}
			cam->data->img[x][y] = get_color_sample_gamma(color);
			free(color);
		}
		ft_printf("printing : %d / %d\n", cam->data->height - y, cam->data->height);
	}
}
