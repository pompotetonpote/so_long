/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:21 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/14 18:37:21 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*new_map_line(char *line)
{
	t_map	*new_map_line;

	new_map_line = malloc(sizeof * new_map_line);
	if (!new_map_line)
		return (NULL);
	new_map_line->map_line = line;
	return (new_map_line);
}

t_map	*extract_map(char **argv)
{
	t_map	*map;
	int		map_file;

	map = NULL;
	map_file = open(*argv, O_RDONLY);
	while (1)
	{
		printf("A\n");
		map = new_map_line(get_next_line(map_file));
		printf("B\n");
		printf("%s", map->map_line);
		if (!map->map_line || !read(map_file, 0, 1))
		{
			printf("joker\n");
			break ;
		}
		printf("C\n");
		map = map->next;
	}
	printf("doublejoker\n");
	free(map->map_line);
	close(map_file);
	return (map);
}
