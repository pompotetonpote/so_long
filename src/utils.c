/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:54:29 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/17 18:00:45 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*free content and linkedlist element*/
void	free_map(t_map **map)
{
	t_map	*tmp;

	if (!map || !(*map) || !(*map)->map_line)
		return ;
	while (*map)
	{
//		printf("free_map : line %s", (*map)->map_line);
		free((*map)->map_line);
//		printf("post_free");
		tmp = (*map)->next;
		free(*map);
		*map = tmp;
	}
	*map = NULL;
}

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
