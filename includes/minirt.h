/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:59 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 14:27:43 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;


int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

void			draw_gradaition(t_data *data, int width, int height);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				mlx_key_handle(int keycode, t_vars *vars);

#endif