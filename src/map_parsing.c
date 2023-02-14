/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:03:13 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/14 16:34:33 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_params	*init_elems(void)
{
	t_params	*elems;

	elems = malloc(sizeof * elems);
	if (!elems)
		return (NULL);
	elems->c = 0;
	elems->e = 0;
	elems->p = 0;
	elems->first_line = 0;
	elems->line_size = 0;
	return (elems);
}

void	map_parsing(t_map **map, t_params *elems)
{
	// t_params	*elems;

	// elems = init_elems();
	if (check_squared_and_lines(map, &elems) == 1)
		ft_putstr("Square & Elems checked !\n");
	elems->map_line_nbr = ft_lstsize(*map);
	elems->tab_tot_size = elems->line_size * elems->map_line_nbr;
	check_path(map, elems);
}
