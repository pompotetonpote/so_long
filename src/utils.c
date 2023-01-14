/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:54:29 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/14 16:49:11 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map **map)
{
	t_map	*tmp;

	if (!map || !(*map))
		return ;
	while (*map)
	{
		tmp = (*map)->next;
		free(*map);
		*map = tmp;
	}
	*map = NULL;
}
