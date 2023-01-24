/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:17:42 by pompote           #+#    #+#             */
/*   Updated: 2023/01/24 15:19:57 by pompote          ###   ########.fr       */
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
