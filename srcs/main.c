/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:06 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 16:19:54 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "chapter.h"

int	main(int argv, char **argc)
{
	int	chapter;

	if (argv < 2 || argv > 3)
		return (ft_printf("Wrong argc\n"));
	chapter = atoi(argc[1]);
	if (chapter == 2 || chapter == 3)
	{
		show_gradation();
		return (0);
	}
	ft_printf("Wrong argc\n");
}
