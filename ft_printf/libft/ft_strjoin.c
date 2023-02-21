/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:23:46 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/07 14:46:26 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*rstr;

	if (!str1 || !str2)
		return (NULL);
	rstr = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	ft_strlcpy(rstr, str1, ft_strlen(str1) + 1);
	ft_strlcpy(rstr + ft_strlen(str1), str2, ft_strlen(str2) + 1);
	return (rstr);
}

/*int	main(void)
{
	char	str1[] = "Hello ";
	char	str2[] = "World!";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
}*/
