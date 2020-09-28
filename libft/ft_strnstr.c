/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:01:28 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:18:33 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	locate;
	char	*find;
	size_t	now;

	find = (char *)haystack;
	if (*needle == '\0')
		return (find);
	now = -1;
	while (*find && (++now < len))
	{
		locate = 0;
		while (locate < ft_strlen(needle))
		{
			if (find[locate] != needle[locate] || (locate + now) >= len)
				break ;
			locate++;
		}
		if (locate == ft_strlen(needle))
			return (find);
		find++;
	}
	return (0);
}
