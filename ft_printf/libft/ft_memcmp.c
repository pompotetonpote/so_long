/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:16:18 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/01 11:02:39 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) str1)[i] == ((unsigned char *) str2)[i])
			i++;
		else
			return (((unsigned char *) str1)[i] - ((unsigned char *) str2)[i]);
	}
	return (0);
}

/*int	main(void)
{
	char	str1[25] = "Coucou, cc'est nous!";
	char	str2[25] = "Coucou, ca'est nous!";

	printf("%d", memcmp(str1, str2, 13));
	printf("%d", ft_memcmp(str1, str2, 13));
}*/
