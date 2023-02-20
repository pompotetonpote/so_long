/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:32:40 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/20 12:16:17 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_tab	*filltab(t_map **map, t_tab *maptab, int bool, t_params *elems)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (bool == 1)
	{
		while (*map)
		{
			while (i < (int) elems->tab_tot_size && j < (int) elems->line_size)
			{
				maptab->tab[i] = (*map)->map_line[j];
				i++;
				j++;
			}
			elems->lines++;
			map = &(*map)->next;
			j = 0;
		}
	}
	else
		while (i < elems->tab_tot_size)
			maptab->tab[i++] = 0;
	return (maptab);
}

t_tab	*init_tab(t_tab *mtab, t_params *elems)
{
	mtab = malloc(sizeof * mtab);
	if (!mtab)
		return (NULL);
	mtab->tab = malloc((elems->tab_tot_size) * sizeof(int));
	if (!(mtab->tab))
		return (NULL);
	return (mtab);
}

void	check_elems_nbr(t_params *parsed_elems, t_params *pathed_elems)
{
	if (parsed_elems->c != pathed_elems->pf_c)
		error_log("Error : All items to be collected are not accessible !\n");
	else if (parsed_elems->e != pathed_elems->pf_e)
		error_log("Error : Path to the exit does not exists !\n");
	else
		ft_putstr("All paths checked !\n");
}

void	check_path(t_map **map, t_params	*elems)
{
	t_tab	*tracetab;
	int		spawn;

	spawn = 0;
	elems->mtab = NULL;
	tracetab = NULL;
	elems->mtab = init_tab(elems->mtab, elems);
	tracetab = init_tab(tracetab, elems);
	elems->pf_c = 0;
	elems->pf_e = 0;
	elems->mtab = filltab(map, elems->mtab, 1, elems);
	tracetab = filltab(map, tracetab, 0, elems);
	spawn = find_spawn(elems->mtab, spawn, elems);
	trackm(elems->mtab, spawn, tracetab, elems);
	check_elems_nbr(elems, elems);
	elems->mtab = filltab(map, elems->mtab, 1, elems);
	elems->pf_c = 0;
	elems->pf_e = 0;
	free(tracetab->tab);
	free(tracetab);
}
