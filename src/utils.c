/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:54:29 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/20 14:20:06 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr(char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, &(*str), 1);
			str++;
		}
	}
}

int	ft_rev_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = ft_strlen(str2);
	if (n == 0)
		return (0);
	while ((str1[n] == str2[i]) && (i > 0 && n > 0)) // && i < n - 1)
	{
		i--;
		n--;
	}
	return ((unsigned char)str1[n] - (unsigned char)str2[i]);
}

int	ft_lstsize(t_map *lst)
{
	int		i;
	t_map	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
