/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:51:19 by yeye              #+#    #+#             */
/*   Updated: 2023/02/21 18:00:26 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_result(t_params *params)
{
	if (params->pf_c <= 1)
	{
		ft_putnbr_fd(params->pf_c, 1);
		ft_putstr(" item of ");
		ft_putnbr_fd(params->c, 1);
		ft_putstr(" collected!\n");
	}
	else
	{
		ft_putnbr_fd(params->pf_c, 1);
		ft_putstr(" items of ");
		ft_putnbr_fd(params->c, 1);
		ft_putstr(" collected!\n");
	}
}

void	pos_analyze_c(t_params *params, int delta)
{
	if (params->mtab->tab[params->pos + delta] == 'C')
	{
		params->pf_c += 1;
		put_result(params);
		if (params->pf_c == params->c)
		{
			ft_putstr("All items collected, the vortex is now open!\n");
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
		ft_putstr("GAME OVER, CONGRATS!");
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
	put_img(params->vars, FLOOR, params);
}
