/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:25:55 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/14 11:24:49 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cmpset(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str1, const char *set)
{
	size_t		start;
	size_t		length;

	if (!str1 || !set)
		return (NULL);
	start = 0;
	while (cmpset(str1[start], set) == 1 && str1[start])
		start++;
	if (start == ft_strlen(str1))
		return (ft_strdup(""));
	length = ft_strlen(str1);
	while (((cmpset(str1[length - 1], set)) == 1) && length > 0)
		length--;
	return (ft_substr(str1, start, length - start));
}

/*int	main(void)
{
	char	str[] = "      ";
	char	set[] = " ";

	printf("%s\n", ft_strtrim(str, set));
	return (0);
}
*/