/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:29:56 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/08 19:32:02 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	show_sky(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	draw_sky(img, 2.0 * aspect_ratio, 2.0, 1.0);
	if (is_save)
		save_bmp(img, "ch4.rt");
	else
		mlx_show(img, "Sky");
	free_img_data(img);
}
