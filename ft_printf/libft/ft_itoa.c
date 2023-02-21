/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:17:20 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/15 14:01:39 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*rstr;
	int		i;
	size_t	nbr;

	i = length(n);
	rstr = (char *)malloc((i + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	rstr[i] = '\0';
	if (n == 0)
		rstr[0] = 48;
	if (n < 0)
	{
		rstr[0] = '-';
		nbr = (size_t) n * -1;
	}
	else
		nbr = n;
	while (nbr > 0)
	{	
		rstr[--i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (rstr);
}

/*int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s", ft_itoa(ft_atoi(argv[1])));
	return (0);
}*/
