/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:57:10 by pompote           #+#    #+#             */
/*   Updated: 2023/01/24 15:25:52 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_line_size(t_map **map, t_elems *elems)
{
	elems->line_size = ft_strlen((*map)->map_line);
	map = &(*map)->next;
	while (map)
	{
		if (ft_strlen((*map)->map_line) != elems->line_size)
			error_log("Error : different line size\n");
		else
		{
			if (!(*map)->next)
				map = &(*map)->next;
			else
				break ;
		}
	}
	return (1);
}

static void	check_1(char *str, t_elems *elems)
{
	if (elems->first_line == 0)
		elems->first_line += 1;
	while (*str)
	{
		if (*str != '1')
			error_log("Error : first or last line not only composed of 1\n");
		str++;
	}
}

static void	check_interline(char *str, t_elems *elems)
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
				error_log("Error : unauthorized letter\n");
			i++;
		}
	}
	else
		error_log("Error : first or last letter != 1\n");
}

static int	check_1_square(t_map *map, t_elems *elems)
{
	while (map)
	{
		if (map->next != NULL && elems->first_line == 0)
			check_1(map->map_line, elems);
		else if (map->next != NULL)
			check_interline(map->map_line, elems);
		else if (map->next == NULL)
			check_1(map->map_line, elems);
		if (elems->e > 1)
			error_log("Error : too many 'exits'\n");
		if (elems->p > 1)
			error_log("Error : too many 'spawn point'\n");
		map = map->next;
	}
	if (elems->e < 1)
		error_log("Error : need one exit\n");
	if (elems->p < 1)
		error_log("Error : need one spawn point\n");
	if (elems->c < 1)
		error_log("Error : need at leat one 'collectible'\n");
	return (1);
}

int	check_squared_and_lines(t_map **map, t_elems **elems)
{
	check_line_size(map, *elems);
	check_1_square(*map, *elems);
	return (1);
}
