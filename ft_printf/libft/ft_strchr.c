/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:14:48 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 16:22:36 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) a)
			return ((char *) str + i);
		i++;
	}
	if (a == '\0')
		return ((char *) str + i);
	else
		return (NULL);
}

/*int main(void)
{
	printf("%s", strchr("feuill\0asse", 'a'));
	printf("%s", ft_strchr("feuill\0asse", 'a'));

}*/
