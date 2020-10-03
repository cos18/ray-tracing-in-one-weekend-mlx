/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:24:03 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/03 16:21:25 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	show_gradation(int is_save)
{
	t_img_data	*img;

	img = create_img_data(256, 256);
	draw_gradaition(img);
	if (is_save)
		return save_bmp(img, "ch2.rt");
	mlx_show(img);
	free_img_data(img);
}