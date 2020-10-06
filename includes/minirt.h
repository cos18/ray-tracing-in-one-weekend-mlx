/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:59 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/04 22:35:51 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "minirt_struct.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_mlx_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_data;

typedef struct	s_img_data {
	int			**img;
	int			width;
	int			height;
}				t_img_data;

int				create_trgb(int t, t_vec *color);
int				get_t(int trgb);
t_vec			*get_color(int trgb);

t_img_data		*create_img_data(int width, int height);
void			free_img_data(t_img_data *data);

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data);
int				mlx_key_handle(int keycode, t_vars *vars);
void			mlx_show(t_img_data *data, char *title);

# define BMP_HEADER_SIZE 122
void			save_bmp(t_img_data *data, char	*filename);

void			draw_gradaition(t_img_data *data);
void			draw_vertical_line(t_img_data *data, int x);
void			draw_horizontal_line(t_img_data *data, int y);
void			draw_sky(t_img_data *data);

#endif