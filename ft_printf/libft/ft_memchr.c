/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:57:17 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 12:07:00 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int a, size_t n)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	c = (unsigned char)a;
	while (i < n)
	{
		if (((unsigned char *) dst)[i] == c)
			return (&(((unsigned char *) dst)[i]));
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	char	dst[25] = "Coucou, c'est nous!";

	printf("%s\n", memchr(dst, 's', 12));
	printf("%s", ft_memchr(dst, 's', 12));
	return (0);
}*/
