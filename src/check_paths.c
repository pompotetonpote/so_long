/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:32:40 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/01 21:10:14 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_elems	*init_elems(t_elems *elems)
{
	elems = malloc(sizeof * elems);
	return (elems);
}

t_tab	*filltab(t_map **map, t_tab *maptab, int bool, t_elems *elems)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("(int) elems->line_size : %d\n", (int) elems->line_size);
	if (bool == 1)
	{
		while (*map)
		{
			while (i < (int) elems->tab_tot_size && j < (int) elems->line_size)
			{
				printf("maptab->tab[%d] : %d, (*map)->map_line[%d] : %d\n", i, maptab->tab[i], j, (*map)->map_line[j]);
				maptab->tab[i] = (*map)->map_line[j];
				printf("maptab->tab[%d] : %d\n\n", i, maptab->tab[i]);
				i++;
				j++;
			}
			printf("before map\n");
			map = &(*map)->next;
			printf("after map\n");
			j = 0;
		}
		printf("filltab mtab -> 0\n");
	}
	else
	{
		while (i < elems->tab_tot_size)
			maptab->tab[i++] = 0;
		printf("filltab tracetab -> 0\n");
	}
	return (maptab);
}

t_tab	*init_tab(t_tab *mtab, t_elems *elems)
{
	mtab = malloc(sizeof * mtab);
	if (!mtab)
		return (NULL);
	mtab->tab = malloc((elems->tab_tot_size) * sizeof(int));
	if (!(mtab->tab))
		return (NULL);
	return (mtab);
}

void	print_tab(t_tab *tab, t_elems *elems)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < elems->tab_tot_size)
	{
		while (j < (int) elems->line_size)
		{
			printf("%d", tab->tab[i]);
			i++;
			j++;
		}
		j = 0;
		printf("\n");
	}
}

int	find_spawn(t_tab *mtab, int spawn, t_elems *elems)
{
	while (mtab->tab[spawn] != 'P' && spawn < elems->tab_tot_size)
	{
		printf("p = %d, spawn = %d, mtab->tab[spawn] = %d\n", 'P', spawn, mtab->tab[spawn]);
		spawn++;
	}
	return (spawn);
}

void	increm_elem(t_tab *maptab, int x, t_elems *nb_elems)
{
	if (maptab->tab[x] == 'c')
		nb_elems->c += 1;
	if (maptab->tab[x] == 'e')
		nb_elems->e += 1;
}

void	trackm(t_tab *mtab, int spawn, t_tab *tracetab, t_elems *nb_elems, t_elems *elems)
{
	tracetab->tab[spawn] = 1;
	if ((spawn - (int) elems->line_size) >= 0 && mtab->tab[spawn - (int) elems->line_size] != '1' && tracetab->tab[spawn - (int) elems->line_size] != 1)
		trackm(mtab, spawn - (int) elems->line_size, tracetab, nb_elems, elems);
	if ((spawn - 1) >= 0 && mtab->tab[spawn - 1] != '1' && tracetab->tab[spawn - 1] != 1)
		trackm(mtab, spawn - 1, tracetab, nb_elems, elems);
	if ((spawn + (int) elems->line_size) >= 0 && mtab->tab[spawn + (int) elems->line_size] != '1' && tracetab->tab[spawn + (int) elems->line_size] != 1)
		trackm(mtab, spawn + (int) elems->line_size, tracetab, nb_elems, elems);
	if ((spawn + 1) >= 0 && mtab->tab[spawn + 1] != '1' && tracetab->tab[spawn + 1] != 1)
		trackm(mtab, spawn + 1, tracetab, nb_elems, elems);
	increm_elem(mtab, spawn, nb_elems);
	mtab->tab[spawn] = '1';
}

void	check_path(t_map **map, t_elems	*elems)
{
	t_tab	*mtab;
	t_tab	*tracetab;
	t_elems	*nb_elems;
	int		spawn;

	spawn = 0;
	nb_elems = NULL;
	mtab = NULL;
	tracetab = NULL;
	mtab = init_tab(mtab, elems);
	tracetab = init_tab(tracetab, elems);
	nb_elems = init_elems(elems);
	if (!nb_elems)
		return ;
	nb_elems->c = 0;
	nb_elems->e = 0;
	mtab = filltab(map, mtab, 1, elems);
	tracetab = filltab(map, tracetab, 0, elems);
	spawn = find_spawn(mtab, spawn, elems);
	printf("----------------spawn = %d-----------------\n", spawn);
	print_tab(mtab, elems);
	print_tab(tracetab, elems);
	trackm(mtab, spawn, tracetab, nb_elems, elems);
	print_tab(mtab, elems);
	print_tab(tracetab, elems);
}
