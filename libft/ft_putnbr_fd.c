/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:11:01 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/02 22:28:36 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long	nn;
	int			locate;
	char		number[15];

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	nn = n;
	if (nn < 0)
		nn *= -1;
	locate = 0;
	while (nn)
	{
		number[locate++] = nn % 10 + '0';
		nn /= 10;
	}
	while (--locate >= 0)
		write(fd, number + locate, 1);
}
