/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:51:28 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 13:54:19 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if ((unsigned char *) dst == NULL && (unsigned char *) src == NULL)
		return (NULL);
	if ((unsigned char *) src < (unsigned char *) dst)
	{	
		while (n--)
		{
			((unsigned char *) dst)[n] = ((unsigned char *) src)[n];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}

/*int main(void)
{
//	char	dst[] = "";
//	char	dst1[] = "";
//	const char	src[] = "";
//	const char	src1[] = "";
	printf("%s\n", memmove("", "" - 1, 0));
	printf("%s\n", ft_memmove("", "" - 1, 0));
	return(0);
} */
