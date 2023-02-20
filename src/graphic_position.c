/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:51:19 by yeye              #+#    #+#             */
/*   Updated: 2023/02/20 12:45:27 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	pos_analyze_c(t_params *params, int delta)
{
	if (params->mtab->tab[params->pos + delta] == 'C')
	{
		params->pf_c += 1;
		if (params->pf_c <= 1)
			printf("%d item of %d collected!\n", params->pf_c, params->c);
		else
			printf("%d items of %d collected!\n", params->pf_c, params->c);
		if (params->pf_c == params->c)
		{
			printf("All items collected, the vortex is now open!\n");
			params->pf_e = 1;
		}
	}
	if (params->mtab->tab[params->pos] == 'C')
		params->mtab->tab[params->pos] = 48;
}

void	pos_analyze_e(t_params *params, int delta)
{
	if (params->mtab->tab[params->pos + delta] == 'E'
		&& params->pf_c == params->c)
	{
		printf("GAME OVER, CONGRATS!");
		mlx_destroy_window(params->vars->mlx, params->vars->win);
		exit (EXIT_SUCCESS);
	}
	if (params->mtab->tab[params->pos + delta] == 'E')
		params->e_switch = 1;
}

void	pos_analyze(t_params *params, int delta)
{
	pos_analyze_c(params, delta);
	pos_analyze_e(params, delta);
//	if (params->e_switch == 1)
//	{
//		params->e_switch = 0;
//		put_img(params->vars, VORTEX, params);
//	}
//	else
	put_img(params->vars, FLOOR, params);
}
