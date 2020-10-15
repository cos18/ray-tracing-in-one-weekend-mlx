/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:06 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 16:26:35 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "chapter.h"

int	main(int argv, char **argc)
{
	int	chapter;

	if (argv < 2 || argv > 3 ||
			(argv == 3 && (ft_strncmp(argc[2], "--save", 6) != 0)))
		return (ft_printf("Wrong argc\n"));
	chapter = atoi(argc[1]);
	if (chapter == 2 || chapter == 3)
		show_gradation(argv - 2);
	else if (chapter == 4)
		show_sky(argv - 2);
	else if (chapter == 5)
		show_s_sphere(argv - 2);
	else if (chapter == 6)
		show_normal_sphere(argv - 2);
	else if (chapter == 7)
		show_normal_sphere_anti(argv - 2);
	else
		ft_printf("Wrong argc\n");
}
