/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:39:31 by yeye              #+#    #+#             */
/*   Updated: 2021/12/14 12:00:38 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(int argc, char **argv)
{
	(void) argc;

	ft_putnbr_fd((ft_atoi(argv[1])), 1);
	return (0);
}*/
