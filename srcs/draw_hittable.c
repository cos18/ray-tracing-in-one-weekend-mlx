;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:55:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/14 05:08:09 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					cal_hittable_color(t_vec *normal)
{
	t_vec			*color;
	int				result;

	color = vec_add_apply(vec_create(1, 1, 1), normal);
	vec_mul_const_apply(color, 0.5 * 255);
	result = create_trgb(0, color);
	free(color);
	return (result);
}

void				draw_hittable(t_img_data *data, t_sky_info *info,
									t_list *lst)
{
	t_sky			*my_sky;
	int				x;
	int				y;
	t_hitlst_info	*lst_info;

	my_sky = init_sky(info, vec_create(0, 0, 0));
	my_sky->data = data;
	y = data->height;
	while ((--y) >= 0)
	{
		x = -1;
		while ((++x) < data->width)
		{
			lst_info = hitlst_info_new(cal_sky_ray(x, y, my_sky), 0, INFINITY,
											hit_record_new());
			if (hitlst_hit(lst, lst_info))
				data->img[x][y] = cal_hittable_color(lst_info->rec->normal);
			free_hitlst_info(lst_info);
		}
	}
	free_sky(my_sky, TRUE);
}
