/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:40:51 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/07 16:15:51 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rstr;

	rstr = NULL;
	i = 0;
	if (!str || !f)
		return (NULL);
	rstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	while (i < ft_strlen(str))
	{
		rstr[i] = (*f)(i, str[i]);
		i++;
	}
	rstr[i] = '\0';
	return (rstr);
}
