/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:40:40 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:21:16 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		locate;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (start < (int)ft_strlen(s1) && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && is_set(s1[end], set))
		end--;
	result = (char *)malloc(((start > end) ? 0 : end - start + 1) + 1);
	if (result)
	{
		locate = -1;
		if (start <= end)
		{
			while (++locate <= end - start)
				result[locate] = s1[start + locate];
		}
		result[((locate == -1) ? 0 : locate)] = '\0';
	}
	return (result);
}
