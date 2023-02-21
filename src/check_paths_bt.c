/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths_bt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:03:38 by pompote           #+#    #+#             */
/*   Updated: 2023/02/21 18:52:07 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	print_tab(t_tab *tab, t_params *elems)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < elems->tab_tot_size)
// 	{
// 		while (j < (int) elems->line_size)
// 		{
// 			ft_putnbr_fd(tab->tab[i], 1);
// 			i++;
// 			j++;
// 		}
// 		j = 0;
// 		ft_putstr("\n");
// 	}
// }

int	find_spawn(t_tab *mtab, int spawn, t_params *elems)
{
	while (mtab->tab[spawn] != 'P' && spawn < elems->tab_tot_size)
		spawn++;
	return (spawn);
}

void	increm_elem(t_tab *maptab, int x, t_params *elems)
{
	if (maptab->tab[x] == 'C')
		elems->pf_c += 1;
	if (maptab->tab[x] == 'E')
		elems->pf_e += 1;
}

int	increm_exit(t_tab *mtab, int spa, int k, t_params *elems)
{
	if (mtab->tab[spa + k] == 'E')
	{
		elems->pf_e += 1;
		return (0);
	}
	return (1);
}

void	trackm(t_tab *mtab, int spa, t_tab *tr_tb, t_params *elems)
{
	int	k;

	k = (int) elems->line_size;
	tr_tb->tab[spa] = 1;
	if ((spa - k) >= 0 && mtab->tab[spa - k] != '1'
		&& increm_exit(mtab, spa, -k, elems) && tr_tb->tab[spa - k] != 1)
		trackm(mtab, spa - k, tr_tb, elems);
	if ((spa - 1) >= 0 && mtab->tab[spa - 1] != '1'
		&& increm_exit(mtab, spa, -1, elems) && tr_tb->tab[spa - 1] != 1)
		trackm(mtab, spa - 1, tr_tb, elems);
	if ((spa + k) >= 0 && mtab->tab[spa + k] != '1'
		&& increm_exit(mtab, spa, k, elems) && tr_tb->tab[spa + k] != 1)
		trackm(mtab, spa + k, tr_tb, elems);
	if ((spa + 1) >= 0 && mtab->tab[spa + 1] != '1'
		&& increm_exit(mtab, spa, 1, elems) && tr_tb->tab[spa + 1] != 1)
		trackm(mtab, spa + 1, tr_tb, elems);
	increm_elem(mtab, spa, elems);
	mtab->tab[spa] = '1';
}
