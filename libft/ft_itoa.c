/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:28:15 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/28 22:46:49 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_len(long long n)
{
	int			result;

	if (!n)
		return (1);
	result = ((n < 0) ? 1 : 0);
	if (n < 0)
		n *= -1;
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char		*result;
	long long	nn;
	char		*put;
	int			locate;

	result = (char *)malloc(get_len(n) + 1);
	if (result)
	{
		put = result;
		nn = n;
		if (nn < 0)
		{
			*(put++) = '-';
			nn *= -1;
		}
		locate = 0;
		n = get_len(nn);
		while (!locate || nn)
		{
			put[n - 1 - (locate++)] = (nn % 10 + '0');
			nn /= 10;
		}
		put[n] = '\0';
	}
	return (result);
}
