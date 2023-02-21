/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:17 by yperonne          #+#    #+#             */
/*   Updated: 2022/03/01 15:54:46 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

# define FLAGS		"-+#0 "
# define ALL_FL		"-+#0 *.0123456789lh"
# define FSPECS		"cspdiuxX%"

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"

# define INT_MIN	-2147483648
# define UINT_MAX	 4294967295

void		ft_getspec(const char *str, va_list arg, int *len);
void		ft_print_c(va_list arg, int **len);
int			ft_printf(const char *str, ...);
void		ft_putchar_i(int c);
void		ft_print_s(va_list arg, int **len);
void		ft_print_p(va_list arg, int **len);
void		ft_print_d(va_list arg, int **len);
void		ft_print_i(va_list arg, int **len);
void		ft_print_u(va_list arg, int **len);
int			length_u(unsigned int nb);
void		ft_print_perc(const char *str, int **len);
void		ft_print_x(const char *str, va_list arg, int **len);
int			ft_print_hexa(unsigned int n, char *base, size_t basesize);
int			ft_print_point(unsigned long n, char *base, size_t basesize);
void		ft_print_p(va_list arg, int **len);
int			ft_print_id(int n);
int			ft_put_u(unsigned long n);

#endif