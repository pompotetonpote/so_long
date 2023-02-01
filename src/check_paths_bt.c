/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:03:38 by pompote           #+#    #+#             */
/*   Updated: 2023/02/01 22:18:55 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		spawn++;
	return (spawn);
}

void	increm_elem(t_tab *maptab, int x, t_elems *elems)
{
	if (maptab->tab[x] == 'C')
		elems->pf_c += 1;
	if (maptab->tab[x] == 'E')
		elems->pf_e += 1;
}

void	trackm(t_tab *mtab, int spa, t_tab *tr_tb, t_elems *elems)
{
	int	k;

	k = (int) elems->line_size;
	tr_tb->tab[spa] = 1;
	if ((spa - k) >= 0 && mtab->tab[spa - k] != '1' && tr_tb->tab[spa - k] != 1)
		trackm(mtab, spa - k, tr_tb, elems);
	if ((spa - 1) >= 0 && mtab->tab[spa - 1] != '1' && tr_tb->tab[spa - 1] != 1)
		trackm(mtab, spa - 1, tr_tb, elems);
	if ((spa + k) >= 0 && mtab->tab[spa + k] != '1' && tr_tb->tab[spa + k] != 1)
		trackm(mtab, spa + k, tr_tb, elems);
	if ((spa + 1) >= 0 && mtab->tab[spa + 1] != '1' && tr_tb->tab[spa + 1] != 1)
		trackm(mtab, spa + 1, tr_tb, elems);
	increm_elem(mtab, spa, elems);
	mtab->tab[spa] = '1';
}
