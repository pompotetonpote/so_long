/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:10:19 by yeye              #+#    #+#             */
/*   Updated: 2021/12/14 10:26:59 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		(*f)(i, &str[i]);
		i++;
	}	
}

/*void	iter(unsigned int i, char *str)
{
	*str += i;
}

int	main(void)
{
	char
	return (0);
}*/
