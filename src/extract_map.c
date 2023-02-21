/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:21 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/21 14:16:26 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Check if linked list is up */
void	linkedlist_check(t_map **map)
{
	int	i;

	i = 1;
	if (map)
	{
		while (*map)
		{
			printf("line %d: %s, -- %p\n", i, (*map)->map_line, &(*map)->map_line);
			map = &(*map)->next;
			i++;
		}
	}
}

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

	map_file = open(*argv, O_RDONLY);
	if (map_file != 0)
		error_log("Erreur lecture .ber\n", NULL, NULL);
	map = new_map_line(get_next_line(map_file));
	if (!map->map_line)
		error_log("Error : .ber file empty", NULL, map);
	head = map;
	while (1)
	{
		map = add_new_map_line(&map, new_map_line(get_next_line(map_file)));
		if (!map)
			break ;
	}

	linkedlist_check(&head);

	line_break_suppression(&head);

	close(map_file);
	return (head);
}
