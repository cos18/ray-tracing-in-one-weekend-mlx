/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:29:56 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/04 22:36:28 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	show_sky(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(800, (int)(800 * aspect_ratio));
	draw_sky(img);
	if (is_save)
		return save_bmp(img, "ch4.rt");
	mlx_show(img, "Sky");
	free_img_data(img);
}