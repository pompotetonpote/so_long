/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:27:40 by yperonne          #+#    #+#             */
/*   Updated: 2022/03/01 11:35:23 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_perc(const char *str, int **len)
{
	ft_putchar_i(*str);
	**len += 1;
}

int	ft_print_point(unsigned long n, char *base, size_t basesize)
{
	int	len;

	len = 0;
	if (n >= basesize)
	{
		len += ft_print_point(n / basesize, base, basesize);
		len += ft_print_point(n % basesize, base, basesize);
	}
	if (n < basesize)
	{
		ft_putchar_i(base[n]);
		len += 1;
	}
	return (len);
}

int	ft_print_hexa(unsigned int n, char *base, size_t basesize)
{
	int	len;

	len = 0;
	if (n >= basesize)
	{
		len += ft_print_hexa(n / basesize, base, basesize);
		len += ft_print_hexa(n % basesize, base, basesize);
	}
	if (n < basesize)
	{
		ft_putchar_i(base[n]);
		len += 1;
	}
	return (len);
}

void	ft_print_x(const char *str, va_list arg, int **len)
{
	if (*str == 'x')
		**len += ft_print_hexa(va_arg(arg, unsigned long), HEXALOW,
				ft_strlen(HEXALOW));
	else
		**len += ft_print_hexa(va_arg(arg, unsigned long), HEXAUPP,
				ft_strlen(HEXAUPP));
}

void	ft_print_p(va_list arg, int **len)
{
	unsigned long	point;

	point = va_arg(arg, unsigned long);
	**len += ft_printf("0x");
	**len += ft_print_point(point, HEXALOW,
			ft_strlen(HEXALOW));
}
