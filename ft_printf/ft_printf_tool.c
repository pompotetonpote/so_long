/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:50:21 by yperonne          #+#    #+#             */
/*   Updated: 2022/03/01 15:54:21 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_i(int c)
{
	write(1, &c, 1);
}

int	ft_print_id(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0 && n > -2147483648)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		len += ft_print_id(n / 10);
		len += ft_print_id(n % 10);
	}
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
		len += 1;
	}
	return (len);
}

int	ft_put_u(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_put_u(n / 10);
		len += ft_put_u(n % 10);
	}
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
		len += 1;
	}
	return (len);
}
