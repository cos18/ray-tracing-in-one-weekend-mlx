/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:06 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/03 15:40:24 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "chapter.h"

int	main(int argv, char **argc)
{
	int	chapter;

	if (argv < 2 || argv > 3 || ( argv == 3 && (ft_strncmp(argc[2], "--save", 6) != 0)))
		return (ft_printf("Wrong argc\n"));
	chapter = atoi(argc[1]);
	if (chapter == 2 || chapter == 3)
	{
		show_gradation(argv - 2);
		return (0);
	}
	ft_printf("Wrong argc\n");
}
