/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:36:21 by yperonne          #+#    #+#             */
/*   Updated: 2022/02/23 11:00:50 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getspec(const char *str, va_list arg, int *len)
{
	if (*str == 'c')
		ft_print_c(arg, &len);
	if (*str == 's')
		ft_print_s(arg, &len);
	if (*str == 'p')
		ft_print_p(arg, &len);
	if (*str == 'd')
		ft_print_d(arg, &len);
	if (*str == 'i')
		ft_print_i(arg, &len);
	if (*str == 'u')
		ft_print_u(arg, &len);
	if (*str == 'x' || *str == 'X')
		ft_print_x(str, arg, &len);
	if (*str == '%')
		ft_print_perc(str, &len);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			len;

	va_start(arg, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_getspec(str, arg, &len);
		}
		else
		{
			ft_putchar_i(*str);
			len += 1;
		}
		str++;
	}
	va_end(arg);
	return (len);
}
