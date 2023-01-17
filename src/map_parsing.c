/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:03:13 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/17 18:00:42 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_line_size(t_map **map, t_elems **elems)
{
	int	i;

	i = 0;
	(*elems)->line_size = ft_strlen((*map)->map_line);
	(*map) = (*map)->next;
	while (*map)
	{
		if (ft_strlen((*map)->map_line) != (*elems)->line_size)
		{
			error("Error : different size line");
		}
		else
			(*map) = (*map)->next;
	}
	return (1);
}

int	check_squared_and_lines(t_map **map, t_elems **elems)
{
	check_line_size(&map, &elems);
	return (1);
}

t_elems	*new_elems_tab(void)
{
	t_elems	*new_tab;

	new_tab = malloc(sizeof new_tab);
	if (!new_tab)
		return (NULL);
	new_tab->c = 0;
	new_tab->e = 0;
	new_tab->p = 0;
	new_tab->line_size = 0;
	return (new_tab);
}

void	map_parsing(t_map **map)
{
	t_elems	*elems;

	(void) map;
	elems = new_elems_tab();
	if (check_squared_and_lines(&map, &elems) == 1)
		ft_pustr("GOOD check square\n");
//	check_elems()
//	check_path()
	free(elems);
	ft_putstr("parsing ongoing\n");
}
