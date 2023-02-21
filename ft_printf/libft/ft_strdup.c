/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:35:59 by yperonne          #+#    #+#             */
/*   Updated: 2022/02/23 13:39:30 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	printf("\n%c\n", *str);
	ptr = (char *) ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(str))
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	free(ptr);
	return (ptr);
}

/*int	main(void)
{
	char	str[10] = "bonjour";
	
	printf("%s\n", ft_strdup(str));
	printf("%s", str);
	return (0);
}*/
