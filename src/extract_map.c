/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:16:21 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/24 14:57:11 by pompote          ###   ########.fr       */
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
	new_map_line->next = NULL;
	return (new_map_line);
}

/*Get last line element*/
t_map	*get_last_map_element(t_map *map)
{
	while (map && map->next != NULL)
		map = map->next;
	return (map);
}

t_map	*get_before_last_map_element(t_map *map)
{
	while (map && map->next && map->next->next != NULL)
		map = map->next;
	return (map);
}

/* Add a new line element at the end of likedlist*/
void	*add_new_map_line(t_map **map, t_map *new_map_line_elem)
{
	t_map	*last;

	last = *map;
	if (!new_map_line_elem)
		return (NULL);
	if (!*map)
	{
		*map = new_map_line_elem;
		return (map);
	}
	last = get_last_map_element(*map);
	last->next = new_map_line_elem;
	return (new_map_line_elem);
}

void	ft_lstadd_back(t_map **map, t_map *new_map_line_elem)
{
	t_map	*tmp;

	tmp = *map;
	if (*map == NULL)
		*map = new_map_line_elem;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_map_line_elem;
	}
}

/* Check if linked list is up */
void	linkedlist_check(t_map **map)
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
	int		i;
	int		map_file;

	i = 0;
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
		if (!map->map_line) /*on Macosx !read(map_file, 0, 1), on linux (!read(map_file, buf, 1))*/
			break ;
		i++;
	}
//	linkedlist_check(&map);
//	free(map->map_line);
//	free(map);	
//	linkedlist_check(&head);
	map = get_before_last_map_element(head);
	map->next = NULL;

	line_break_suppression(&head);
//	linkedlist_check(&head);


	close(map_file);
	return (head);
}
