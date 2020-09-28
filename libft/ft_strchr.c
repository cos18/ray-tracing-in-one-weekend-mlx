/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:52:18 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:16:11 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		is_end;
	char	*now;

	is_end = 0;
	now = (char *)s;
	while (1)
	{
		if (*now == c)
			break ;
		if (*now == '\0')
		{
			is_end = 1;
			break ;
		}
		now++;
	}
	return ((is_end) ? NULL : now);
}
