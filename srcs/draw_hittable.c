/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:55:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 21:12:10 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					cal_hittable_color(t_list *lst, t_hitlst_info *info)
{
	t_vec			*color;
	t_vec			*tmp;
	int				result;
	double			t;

	if (hitlst_hit(lst, info))
	{
		color = vec_add_apply(vec_create(1, 1, 1), info->rec->normal);
		vec_mul_const_apply(color, 0.5);
	}
	else
	{
		tmp = vec_unit(info->ray->dir);
		t = 0.5 * (tmp->y + 1.0);
		free(tmp);
		color = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
		tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
		vec_add_apply(color, tmp);
		free(tmp);
	}
	result = get_color_val(color);
	free(color);
	return (result);
}

void				draw_hittable(t_camera *cam, t_list *lst)
{
	int				x;
	int				y;
	double			u;
	double			v;
	t_hitlst_info	*lst_info;

	y = cam->data->height;
	while ((--y) >= 0)
	{
		x = -1;
		while ((++x) < cam->data->width)
		{
			u = (double)x / (cam->data->width - 1);
			v = (double)y / (cam->data->height - 1);
			lst_info = hitlst_info_new(camera_get_ray(cam, u, v), 0, INFINITY,
											hit_record_new());
			cam->data->img[x][y] = cal_hittable_color(lst, lst_info);
			free_hitlst_info(lst_info, FALSE);
		}
	}
}
