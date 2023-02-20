/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:57:10 by pompote           #+#    #+#             */
/*   Updated: 2023/02/20 17:05:32 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_line_size(t_map **map, t_params *elems)
{
	elems->line_size = ft_strlen((*map)->map_line);
	map = &(*map)->next;
	while (map)
	{
		if (ft_strlen((*map)->map_line) != elems->line_size)
			error_log("Error : different line size", elems, *map);
		else
		{
			if ((*map)->next)
				map = &(*map)->next;
			else
				break ;
		}
	}
}

static void	check_1(char *str, t_params *elems, t_map *map)
{
	if (elems->first_line == 0)
		elems->first_line += 1;
	while (*str)
	{
		if (*str != '1')
			error_log("Error : first or last line not only composed of 1",
				elems, map);
		str++;
	}
}

static void	check_interline(char *str, t_params *elems, t_map *map)
{
	int	i;

	i = 1;
	if ((str[0] == '1') && (str[elems->line_size - 1] == '1'))
	{
		while (str[i])
		{
			if (str[i] == 'E' || str[i] == 'C' || str[i] == 'P'
				|| str[i] == '0' || str[i] == '1')
			{
				if (str[i] == 'E')
					elems->e += 1;
				else if (str[i] == 'C')
					elems->c += 1;
				else if (str[i] == 'P')
					elems->p += 1;
			}
			else
				error_log("Error : unauthorized letter", elems, map);
			i++;
		}
	}
	else
		error_log("Error : first or last letter != 1", elems, map);
}

static int	check_1_square(t_map *map, t_params *elems)
{
	while (map)
	{
		if (map->next != NULL && elems->first_line == 0)
			check_1(map->map_line, elems, map);
		else if (map->next != NULL)
			check_interline(map->map_line, elems, map);
		else if (map->next == NULL)
			check_1(map->map_line, elems, map);
		if (elems->e > 1)
			error_log("Error : too many 'exits'", elems, map);
		if (elems->p > 1)
			error_log("Error : too many 'spawn point'", elems, map);
		map = map->next;
	}
	if (elems->e < 1)
		error_log("Error : need one exit", elems, map);
	if (elems->p < 1)
		error_log("Error : need one spawn point", elems, map);
	if (elems->c < 1)
		error_log("Error : need at leat one 'collectible'", elems, map);
	return (1);
}

int	check_squared_and_lines(t_map **map, t_params **elems)
{
	check_line_size(map, *elems);
	check_1_square(*map, *elems);
	return (1);
}
