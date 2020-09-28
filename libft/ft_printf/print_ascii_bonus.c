/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 00:39:26 by sunpark           #+#    #+#             */
/*   Updated: 2020/07/03 21:30:07 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_real_percent(t_percent *p)
{
	int	result;

	result = 0;
	if (p->sort != 2)
		result += print_sort(p, 1);
	ft_putchar_fd('%', 1);
	result += 1;
	if (p->sort == 2)
		result += print_sort(p, 1);
	return (result);
}

int	print_char(t_percent *p, va_list ap)
{
	int		result;
	char	print;

	result = 0;
	if (p->sort != 2)
		result += print_sort(p, 1);
	print = (char)va_arg(ap, int);
	ft_putchar_fd(print, 1);
	result += 1;
	if (p->sort == 2)
		result += print_sort(p, 1);
	return (result);
}

int	print_string(t_percent *p, va_list ap)
{
	int		result;
	char	*print;
	int		p_len;
	int		cnt;

	result = 0;
	print = (char *)va_arg(ap, char *);
	if (print == NULL)
		print = "(null)";
	p_len = ft_strlen(print);
	if (p->precision != -1)
		p_len = (p_len > p->precision) ? p->precision : p_len;
	if (p->sort != 2)
		result += print_sort(p, p_len);
	cnt = -1;
	while (++cnt < p_len)
		ft_putchar_fd(print[cnt], 1);
	result += p_len;
	if (p->sort == 2)
		result += print_sort(p, p_len);
	return (result);
}
