/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:24:16 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/14 16:29:50 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*rstr;

	rstr = NULL;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		rstr = ft_calloc(1, sizeof(char));
		if (!rstr)
			return (NULL);
		return (rstr);
	}
	if (ft_strlen(str) < len)
		rstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	else if (ft_strlen(str) >= len)
		rstr = malloc((len + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	ft_strlcpy(rstr, str + start, len + 1);
	return (rstr);
}
