/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdiu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:32 by yperonne          #+#    #+#             */
/*   Updated: 2022/03/01 11:35:16 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(va_list arg, int **len)
{
	ft_putchar_i(va_arg(arg, int));
	**len += 1;
}

void	ft_print_s(va_list arg, int **len)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		**len += 6;
		return ;
	}
	while (*str)
	{
		ft_putchar_i(*str++);
		**len += 1;
	}
}

void	ft_print_d(va_list arg, int **len)
{
	int	argint;

	argint = va_arg(arg, int);
	if (argint < 0 && argint != INT_MIN)
		**len += 1;
	**len += ft_print_id(argint);
}

void	ft_print_i(va_list arg, int **len)
{
	int	argint;

	argint = va_arg(arg, int);
	if (argint < 0 && argint != INT_MIN)
		**len += 1;
	**len += ft_print_id(argint);
}

void	ft_print_u(va_list arg, int **len)
{
	unsigned int	argint;

	argint = va_arg(arg, unsigned int);
	**len += ft_put_u(argint);
}
