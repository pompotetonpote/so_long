/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:21 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/01 15:06:27 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Check if linked list is up */
/*void	linkedlist_check(t_map **map)
{
	int	i;

	i = 1;
	if (map)
	{
		while (*map)
		{
			printf("line %d: %s\n", i, (*map)->map_line);
			map = &(*map)->next;
			i++;
		}
	}
}*/

void	line_break_suppression(t_map **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (*map)
		{
			i = 0;
			while ((*map)->map_line[i])
			{
				if ((*map)->map_line[i] == '\n')
					(*map)->map_line[i] = '\0';
				i++;
			}
			map = &(*map)->next;
		}
	}
}

/*extract the line of the map file and do a linkedlist of all element*/
t_map	*extract_map(char **argv)
{
	t_map	*map;
	t_map	*head;
	int		map_file;

	map = NULL;
	head = NULL;
	map_file = open(*argv, O_RDONLY);
	if (map_file == -1)
		return (0);
	map = new_map_line(get_next_line(map_file));
	head = map;
	while (1)
	{
		map = add_new_map_line(&map, new_map_line(get_next_line(map_file)));
		if (!map->map_line)
			break ;
	}
//	free(map->map_line);
//	free(map);	
	map = get_before_last_map_element(head);
	map->next = NULL;
	line_break_suppression(&head);
//	linkedlist_check(&head);
	close(map_file);
	return (head);
}
