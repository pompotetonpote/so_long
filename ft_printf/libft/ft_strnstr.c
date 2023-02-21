/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:16:13 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 15:12:20 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*to_find == 0)
		return ((char *) str);
	while (str[i] && i < len)
	{
		k = 0;
		while (str[i + k] == to_find[k] && i + k < len)
		{
			if (to_find[k + 1] == '\0')
				return ((char *) str + i);
			k++;
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
	printf("%s\n", strnstr("is there a nyacat ?", "is there a nyacat ?", 20));
	printf("%s", ft_strnstr("is there a nyacat ?", "is there a nyacat ?", 20));

	return (0);
}*/
