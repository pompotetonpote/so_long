/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:32:40 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:32 by yperonne         ###   ########.fr       */
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

void	check_path(t_map **map, t_elems	*elems)
{
	t_tab	*mtab;
	t_tab	*tracetab;
	t_elems	*nb_elems;

	nb_elems = NULL;
	mtab = NULL;
	tracetab = NULL;
	mtab = init_tab(mtab, elems);
	tracetab = init_tab(tracetab, elems);
	nb_elems = init_elems(elems);
	if (!nb_elems)
		return ;
	printf("after init\n");
	nb_elems->c = 0;
	nb_elems->e = 0;
	printf("after nb_elems init\n");
	mtab = filltab(map, mtab, 1, elems);
	tracetab = filltab(map, tracetab, 0, elems);
	print_tab(mtab, elems);
	print_tab(tracetab, elems);

}