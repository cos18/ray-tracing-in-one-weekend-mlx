/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:26:48 by sunpark           #+#    #+#             */
/*   Updated: 2020/07/04 14:52:40 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf_bonus.h"

int				get_hex_len(unsigned int n)
{
	return ((n < 16) ? 1 : 1 + get_hex_len(n / 16));
}

unsigned int	hex_pow(int n)
{
	return ((n == 0) ? 1 : hex_pow(n - 1) * 16);
}

void			print_hex_num(unsigned int num, t_percent *p, int is_upper)
{
	int		locate;
	int		minnum;

	if (num == 0 && p->precision == 0)
	{
		if (p->width)
			ft_putchar_fd(' ', 1);
		return ;
	}
	locate = get_hex_len(num);
	while (locate--)
	{
		minnum = num / hex_pow(locate) % 16;
		if (minnum < 10)
			ft_putchar_fd('0' + minnum, 1);
		else
			ft_putchar_fd((is_upper ? 'A' : 'a') + minnum - 10, 1);
	}
}

int				print_hex(t_percent *p, va_list ap, int is_upper)
{
	unsigned int	print;
	int				result;
	int				len;
	int				dlen;

	print = va_arg(ap, unsigned int);
	dlen = get_hex_len(print);
	len = ((p->precision > dlen) ? p->precision : dlen);
	result = len;
	if (p->sort != 2)
	{
		if (p->precision != -1)
			p->sort = 0;
		result += print_sort(p, len);
	}
	while (len > dlen && (len--))
		ft_putchar_fd('0', 1);
	print_hex_num(print, p, is_upper);
	len = ((p->precision > len) ? p->precision : len);
	if (p->sort == 2)
		result += print_sort(p, len);
	return (result - ((print || p->precision || p->width) ? 0 : 1));
}
