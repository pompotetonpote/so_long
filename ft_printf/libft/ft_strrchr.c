/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:39:42 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 16:29:20 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	int	i;

	i = 0;
	if (!a || a == 0)
		return ((char *) str + ft_strlen(str));
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char) a)
			return ((char *) &str[i]);
		i--;
	}
	return (NULL);
}

/*int main(void)
{
	printf("%s", strrchr("feuill\0asse", '\0'));
	printf("%s", ft_strrchr("feuill\0asse", '\0'));

}*/
