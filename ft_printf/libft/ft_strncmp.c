/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:46:17 by yperonne          #+#    #+#             */
/*   Updated: 2021/11/30 12:11:29 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (str1[i] && str2[i]) && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/*int main(void)
{

	printf("%d", strncmp("\x12\xff", "\x12\x02", 6));
	printf("%d", ft_strncmp("\x12\xff", "\x12\x02", 6));
	return (0);
}*/
