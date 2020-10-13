/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:59 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/14 05:33:39 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "minirt_struct.h"
# include "minirt_const.h"
# include <stdlib.h>
# include <math.h>

int				create_trgb(int t, t_vec *color);
int				get_t(int trgb);
t_vec			*get_color(int trgb);

t_img_data		*create_img_data(int width, int height);
void			free_img_data(t_img_data *data);

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data);
int				mlx_key_handle(int keycode);
void			mlx_show(t_img_data *data, char *title);

# define BMP_HEADER_SIZE 122
void			save_bmp(t_img_data *data, char	*filename);

void			draw_gradaition(t_img_data *data);
void			draw_vertical_line(t_img_data *data, int x);
void			draw_horizontal_line(t_img_data *data, int y);

typedef struct	s_sky_info
{
	double		viewport_width;
	double		viewport_height;
	double		focal_length;
}				t_sky_info;


typedef struct	s_sky
{
	t_img_data	*data;
	t_vec		*horizontal;
	t_vec		*vertical;
	t_vec		*lower_left_corner;
	t_vec		*origin;
}				t_sky;

t_sky_info		*init_sky_info(double viewport_width, double viewport_height,
								double focal_length);
t_sky			*init_sky(t_sky_info *info, t_vec *origin);
int				cal_sky_color(t_ray *r);
void			free_sky(t_sky *my_sky, int is_origin_free);
void			draw_sky(t_img_data *data, t_sky_info *info);

t_ray			*cal_sky_ray(int x, int y, t_sky *my_sky);

typedef struct	s_sphere
{
	t_vec		*center;
	double		radius;
	t_vec		*color;
}				t_sphere;

t_sphere		*init_sphere(t_vec *center, double radius, t_vec *color);
void			free_sphere(t_sphere *s);
void			draw_sphere(t_img_data *data, t_sky_info *info, t_sphere *s);

void			draw_s_sphere(t_img_data *data, t_sky_info *info, t_sphere *s);

int				sphere_hit(void *s, t_ray *r, t_hitlst_info *info,
							t_hit_record *rec);

void			draw_hittable(t_img_data *data, t_sky_info *info, t_list *lst);

#endif
