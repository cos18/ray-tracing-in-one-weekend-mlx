/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable_pthread_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:55:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/23 14:34:51 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void				*render(void *arg)
{
	int				x;
	int				y;
	int				locate;
	t_vec			*color;
	t_hitlst_info	*info;
	t_thread_info	*tinfo;

	tinfo = (t_thread_info *)arg;
	y = tinfo_get_y_init_value(tinfo);
	while ((--y) >= (tinfo_get_step(tinfo) * (tinfo->tnum - 1)))
	{
		x = -1;
		while ((++x) < tinfo->cam->data->width)
		{
			color = vec_create(0, 0, 0);
			locate = -1;
			while ((++locate) < ANTI_SAMPLES)
			{
				info = get_hitlst_by_locate(x, y, tinfo->cam);
				get_hittable_material_color(tinfo->lst, &info, color);
			}
			tinfo->cam->data->img[x][y] = get_color_sample_gamma(color);
			free(color);
		}
		ft_printf("Finish render line %d\n", y);
	}
	ft_printf("Thread %d finish!\n", tinfo->tnum);
	free(tinfo);
	return (NULL);
}

void				draw_hittable_pthread(t_camera *cam, t_list *lst)
{
	pthread_t		*threads;
	int				pnum;
	t_thread_info	*info;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * PTHREAD_CNT);
	pnum = 0;
	while (++pnum <= PTHREAD_CNT)
	{
		info = tinfo_new(cam, lst, pnum);
		pthread_create(&(threads[pnum - 1]), NULL, render, (void *)info);
	}
	pnum = 0;
	while (++pnum <= PTHREAD_CNT)
		pthread_join(threads[pnum - 1], NULL);
	free(threads);
}
