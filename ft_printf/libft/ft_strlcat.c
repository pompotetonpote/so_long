/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:33:42 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 14:21:42 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = ft_strlen(dst);
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[k] && i + k < dstsize - 1)
	{	
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[k]));
}

/*int main(void)
{
	char	dst[50] = "Coucou, c'est nous!";
	char	dst2[50] = "Coucou, c'est nous!";
	char	src[50] = "the cake is a lie !\0I'm hidden lol\r\n";

	printf("Avant strlcat : %s\n", dst);
	printf("%lu\n", strlcat(dst, src, 0));
	printf("Apres strlcat : %s\n", dst);
	printf("Avant strlcat : %s\n", dst2);
	printf("%lu\n", ft_strlcat(dst2, src, 0));
	printf("Apres strlcat : %s\n", dst2);

	return (0);
}*/
