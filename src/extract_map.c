/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:21 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/18 01:12:48 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Add a linkedlist element*/
t_map	*new_map_line(char *line)
{
	t_map	*new_map_line;

	new_map_line = malloc(sizeof * new_map_line);
	if (!new_map_line)
		return (NULL);
	new_map_line->map_line = line;
	return (new_map_line);
}

/*Get last line element*/
t_map	*get_last_map_element(t_map *map)
{
	while (map && map->next != NULL)
		map = map->next;
	return (map);
}

/* Add a new line element at the end of likedlist*/
void	add_new_map_line(t_map **map, t_map *new_map_line_elem)
{
	t_map	*last;

	if (!new_map_line_elem)
		return ;
	if (!*map)
	{
		*map = new_map_line_elem;
		return ;
	}
	last = get_last_map_element(*map);
	last->next = new_map_line_elem;
}

/* Check if linked list is up */
void	linkedlist_check(int i, t_map **map)
{
	int	r;

	r = i + 1;
	if (map)
	{
		while (*map)
		{
			printf("line %d: %s\n", r - i, (*map)->map_line);
			map = &(*map)->next;
			i--;
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
	int		i;
	int		map_file;
	char	*buf[1];

	i = 0;
	map = NULL;
	map_file = open(*argv, O_RDONLY);
	while (1)
	{
		if (i == 0)
			map = new_map_line(get_next_line(map_file));
		else
			add_new_map_line(&map, new_map_line(get_next_line(map_file)));
		if (!map->map_line || !read(map_file, buf, 1)) /*on Macosx !read(map_file, 0, 1), on linux (!read(map_file, buf, 1))*/
			break ;
		lseek(map_file, -1, SEEK_CUR);
		i++;
	}
	line_break_suppression(&map);
	linkedlist_check(i, &map);
	close(map_file);
	return (map);
}
