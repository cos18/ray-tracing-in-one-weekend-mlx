/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:06:38 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 14:29:29 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_color_val(t_vec *color)
{
	int	x;
	int	y;
	int	z;

	x = clamp(color->x, 0.0, 0.999) * 256.0;
	y = clamp(color->y, 0.0, 0.999) * 256.0;
	z = clamp(color->z, 0.0, 0.999) * 256.0;
	return (x << 16 | y << 8 | z);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

t_vec	*get_color(int rgb)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = (rgb & (0xFF << 16)) >> 16;
	result->y = (rgb & (0xFF << 8)) >> 8;
	result->z = rgb & 0xFF;
	return (result);
}
