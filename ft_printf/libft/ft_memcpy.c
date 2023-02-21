/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:29:36 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/01 11:12:31 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if ((unsigned char *) dst == NULL && (unsigned char *) src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	printf("%s", memcpy(((void *)0), ((void *)0), 3));
	printf("%s", ft_memcpy(((void *)0), ((void *)0), 3));
	return(0);
}*/
