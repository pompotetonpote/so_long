/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:57:11 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 11:49:37 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int a, size_t len)
{
	unsigned int	i;
	unsigned char	r;

	i = 0;
	r = (unsigned char)a;
	while (i < len)
	{
		((unsigned char *) dst)[i] = r;
		i++;
	}
	return (dst);
}

/*int	main(void)
{	
	char	str[50] = "Coucou c'est nous!";
	char	str2[50] = "Coucou c'est nous22!";
	printf("\nAvant le memset(): %s\n", str);
	printf("Apres le memset : %s", memset(str, 'A', 5));
	printf("\nAvant le memset(): %s\n", str2);
	printf("Apres le memset : %s", ft_memset(str2, 'A', 5));
	return(0);
}*/
