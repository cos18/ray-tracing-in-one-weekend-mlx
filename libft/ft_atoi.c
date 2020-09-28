/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:14:43 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:12:29 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isblank(char a)
{
	return (a == '\t' || a == '\v' || a == '\f' || \
			a == '\r' || a == '\n' || a == ' ');
}

int			ft_atoi(const char *str)
{
	unsigned long long	ans;
	int					minus;

	minus = 1;
	ans = 0;
	while (isblank(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		minus = ((*str == '-') ? -1 : 1);
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			break ;
		ans *= 10;
		ans += (*str - '0');
		str++;
	}
	return ((int)(ans * minus));
}
