/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:03:13 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/18 17:48:16 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_params	*init_elems(void)
{
	t_params	*elems;

	elems = malloc(sizeof * elems);
	elems->vars = malloc(sizeof (t_vars));
	if (!elems)
		return (NULL);
	if (!elems->vars)
		return (NULL);
	elems->e = 0;
	elems->pf_e = 0;
	elems->c = 0;
	elems->pf_c = 0;
	elems->p = 0;
	elems->moves = 0;
	elems->first_line = 0;
	elems->map_line_nbr = 0;
	elems->tab_tot_size = 0;
	elems->lines = 0;
	elems->pos = 0;
	elems->lmove = 0;
	elems->rmove = 0;
	elems->dmove = 0;
	elems->umove = 0;
	return (elems);
}

void	map_parsing(t_map **map, t_params *elems)
{
	if (check_squared_and_lines(map, &elems) == 1)
		ft_putstr("Square & Elems checked !\n");
	elems->map_line_nbr = ft_lstsize(*map);
	elems->tab_tot_size = elems->line_size * elems->map_line_nbr;
	check_path(map, elems);
	free_map(map);
}
