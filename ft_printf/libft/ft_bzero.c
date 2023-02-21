/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:08:35 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/01 13:15:33 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && n != 0)
	{
		((unsigned char *) dst)[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	str[25] = "Coucou c'est nous!";
	char	str2[25] = "Coucou c'est nous!2";

	printf("Avant le bzero: %s\n", str);
	printf("Apres le bzero: %s\n", bzero(str, 3));
	printf("Avant le bzero: %s\n", str2);
	printf("Apres le bzero: %s\n", bzero(str2, 3));
	return(0);
}*/
