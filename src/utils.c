/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:54:29 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/21 17:59:25 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr(char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, &(*str), 1);
			str++;
		}
	}
}

int	ft_rev_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = ft_strlen(str2);
	if (n == 0)
		return (0);
	while ((str1[n] == str2[i]) && (i > 0 && n > 0)) // && i < n - 1)
	{
		i--;
		n--;
	}
	return ((unsigned char)str1[n] - (unsigned char)str2[i]);
}

int	ft_lstsize(t_map *lst)
{
	int		i;
	t_map	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n > -2147483648)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}
