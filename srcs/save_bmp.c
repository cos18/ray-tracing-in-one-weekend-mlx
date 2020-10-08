/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:18:55 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/08 19:33:25 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		raw_fill_header(t_img_data *data,
								char **raw_bmp, unsigned int img_size)
{
	*(unsigned short *)*raw_bmp = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*raw_bmp + 2) = (img_size + BMP_HEADER_SIZE);
	*(unsigned int *)(*raw_bmp + 6) = 0u;
	*(unsigned char *)(*raw_bmp + 10) = BMP_HEADER_SIZE;
	*(unsigned int *)(*raw_bmp + 14) = BMP_HEADER_SIZE - 14;
	*(unsigned int *)(*raw_bmp + 18) = data->width;
	*(unsigned int *)(*raw_bmp + 22) = data->height;
	*(unsigned short *)(*raw_bmp + 26) = 1;
	*(unsigned short *)(*raw_bmp + 28) = 24;
	*(unsigned int *)(*raw_bmp + 30) = 0;
	*(unsigned int *)(*raw_bmp + 34) = img_size;
	*(unsigned int *)(*raw_bmp + 38) = 3780;
	*(unsigned int *)(*raw_bmp + 42) = 3780;
	*(int *)(*raw_bmp + 46) = 0;
	*(int *)(*raw_bmp + 50) = 0;
}

void		raw_fill_data(t_img_data *data, char *raw_bmp)
{
	t_vec	*color;
	int		w;
	int		h;
	int		locate;

	locate = BMP_HEADER_SIZE + 1;
	h = -1;
	while ((++h) < data->height)
	{
		w = -1;
		while ((++w) < data->width)
		{
			color = get_color(data->img[w][h]);
			*(raw_bmp + locate++) = (unsigned char)(color->y);
			*(raw_bmp + locate++) = (unsigned char)(color->x);
			*(raw_bmp + locate++) = (unsigned char)(color->z);
			free(color);
		}
	}
}

char		*get_bmp_filename(char *filename)
{
	char	*result;

	result = (char *)malloc(ft_strlen(filename) + 2);
	ft_strlcpy(result, filename, ft_strlen(filename) - 1);
	result[ft_strlen(filename) - 2] = 'b';
	result[ft_strlen(filename) - 1] = 'm';
	result[ft_strlen(filename)] = 'p';
	result[ft_strlen(filename) + 1] = 0;
	return (result);
}

void		save_bmp(t_img_data *data, char *filename)
{
	char	*bmp_filename;
	char	*raw_bmp;
	int		img_size;
	int		locate;
	int		fd;

	bmp_filename = get_bmp_filename(filename);
	img_size = data->width * data->height * 3;
	raw_bmp = (char *)malloc(img_size + BMP_HEADER_SIZE);
	locate = 0;
	while (locate < img_size + BMP_HEADER_SIZE)
		raw_bmp[locate++] = 0;
	raw_fill_header(data, &raw_bmp, img_size);
	raw_fill_data(data, raw_bmp);
	fd = open(bmp_filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	write(fd, raw_bmp, (img_size + BMP_HEADER_SIZE));
	close(fd);
	free(bmp_filename);
	free(raw_bmp);
}
